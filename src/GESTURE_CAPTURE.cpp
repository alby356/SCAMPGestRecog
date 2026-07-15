// ---------------------------------------------------------------------------
// Adapted from FUNCS_DIGIT_EXTRACTION.hpp in
// github.com/lauriebose/Scamp5-MNIST_AREG_CNN_example -- see GESTURE_CAPTURE.hpp
// for why these are renames of the reference's routines, not reinventions.
// NOT compiled or run in this environment; ported for correctness against
// the real API, unverified against real hardware.
// ---------------------------------------------------------------------------

#include <scamp5.hpp>
#include "GESTURE_CAPTURE.hpp"
#include "MISC_FUNCTIONS.hpp"
#include "IMG_TF.hpp"

using namespace SCAMP5_PE;

void extract_gesture_blob_from_F_into_R11(bool white_on_black_blob, int threshold, int size, int xpos, int ypos)
{
	////////////////////////////////////////////////////////////////////////
	//THRESHOLD THE WHOLE FRAME DIRECTLY -- NO FLOOD-FILL BLOB ISOLATION
	//
	// The reference's digit-extraction seeds a flood-fill from a FIXED small
	// rectangle at (100,100)-(160,160), then only keeps whichever connected
	// blob of thresholded pixels happens to touch that seed box. That's
	// needed for a small handwritten digit that might not be the only mark
	// on a page. A hand gesture frame has a uniformly dark background with
	// nothing else to confuse it with, so the raw threshold result already
	// IS the hand silhouette -- and critically, removing the seed-box
	// dependency fixes a real observed failure: on actual hardware, the
	// duplicated/tiled output was solid black (nothing reached the conv
	// layer) whenever the hand didn't happen to overlap that fixed seed
	// rectangle. This also now matches train.py's actual preprocessing
	// exactly (a plain whole-frame Otsu threshold, no blob isolation) --
	// the two had diverged, which would have hurt accuracy even once the
	// black-frame bug was fixed.
	//
	// Trade-off, stated plainly: without flood-fill connected-component
	// isolation, any stray bright noise pixels elsewhere in frame would
	// enlarge the bounding box below and throw off the auto-center/scale
	// step. Fine for a clean dark background (as observed); revisit with a
	// minimum-blob-size filter if a noisier background causes problems.

	scamp5_load_in(E, threshold);
	scamp5_kernel_begin();
		sub(F, F, E);
	scamp5_kernel_end();
	if (!white_on_black_blob)
	{
		scamp5_kernel_begin();
			where(F);
				NOT(R11, FLAG);
			all();
		scamp5_kernel_end();
	}
	else
	{
		scamp5_kernel_begin();
			where(F);
				MOV(R11, FLAG);
			all();
		scamp5_kernel_end();
	}

	uint8_t bound_box_data[4];
	scamp5_scan_boundingbox(R11, bound_box_data);

	int box_x = bound_box_data[1];
	int box_y = bound_box_data[0];
	int box_w = bound_box_data[3] - bound_box_data[1];
	int box_h = bound_box_data[2] - bound_box_data[0];
	if (box_w <= 0 || box_h <= 0)
	{
		// nothing above threshold this frame (e.g. hand out of view) --
		// leave R11 as the (empty) raw threshold result rather than run the
		// centering/scaling math on a degenerate box
		return;
	}
	int offsetx = box_x + box_w / 2 - 128;
	int offsety = box_y + box_h / 2 - 128;

	//CENTER THE HAND SILHOUETTE
	MISC_FUNCTIONS::shift_R11(offsetx, -offsety);

	////////////////////////////////////////////////////////////////////////
	//SCALE HAND SILHOUETTE TO FILL REGISTER

	int scaling = (size - box_w) / 2;
	if ((size - box_h) / 2 < scaling)
	{
		scaling = (size - box_h) / 2;
	}

	const int additional_scaling_steps = 80;

	if (scaling != 0)
	{
		bool scale_down = scaling < 0;
		// BUG (inherited from the reference's extract_character_from_F_into_R11,
		// present in both its scaling>0 and scaling<=0 branches): this call
		// hardcoded `false` for scale_down instead of passing the just-computed
		// `scale_down`, AND passed `scaling` directly even though SCALE()'s
		// internal loop is `for (unsigned char n = 0; n < scaling_mag; n++)` --
		// a negative scaling_mag makes that loop bound false immediately, so
		// the call was silently a no-op whenever shrinking was needed. For a
		// centered MNIST digit only ever needing mild upscaling this went
		// unnoticed; a hand filling most of the 256x256 frame needs *shrinking*
		// down to `size` (e.g. box_w ~200 -> size ~64, scaling ~-68), which hit
		// this exact no-op path -- diagnosed from real hardware output (tiled
		// panel staying solid black even after the flood-fill fix, since this
		// coarse scale-down step never ran and the ~80-step fine loop below
		// can't make up that much ground on its own within budget).
		// Clamp to scaling_rowcol_order's actual bound (88 entries in
		// IMG_SCALING_DIGITAL.cpp) -- STEP_SCALE_*_R11 indexes that table
		// directly with no bounds check, and a hand filling much of the
		// 256x256 frame can need a much larger shrink magnitude than the
		// reference's centered-digit use case ever did (e.g. size=45 against
		// a hand ~200px wide needs magnitude ~78, and a closer/bigger hand
		// can exceed 88 outright). The remaining gap, if any, is picked up by
		// the additional_scaling_steps fine-tune loop below.
		int coarse_scaling_mag = scale_down ? -scaling : scaling;
		if (coarse_scaling_mag > 87) coarse_scaling_mag = 87;
		IMGTF::SCALING::DIGITAL::SCALE(R11, coarse_scaling_mag, scale_down);

		////////////////////////////////////////////////////////////////////////
		//MAKE MASK THAT FRAMES THE EDGES OF THE IMAGE PLANE

		int tmp = 128 - size / 2;
		MISC_FUNCTIONS::load_rect_into_DREG(DENUM::R1, tmp, tmp, size, size);
		scamp5_kernel_begin();
			NOT(R10, R1);
		scamp5_kernel_end();

		//SCALE UP/DOWN BIT BY BIT UNTIL HIT REGISTER EDGES
		for (int n = 0; n < additional_scaling_steps; n++)
		{
			if (!scale_down)
			{
				IMGTF::SCALING::DIGITAL::STEP_SCALE_UP_R11(n);
				scamp5_kernel_begin();
					AND(R1, R11, R10);
				scamp5_kernel_end();
				if (scamp5_global_or(R1))
				{
					break;
				}
			}
			else
			{
				IMGTF::SCALING::DIGITAL::STEP_SCALE_DOWN_R11(n);
				scamp5_kernel_begin();
					AND(R1, R11, R10);
				scamp5_kernel_end();
				if (!scamp5_global_or(R1))
				{
					break;
				}
			}
		}
	}

	MISC_FUNCTIONS::shift_R11(-xpos + 128, +ypos - 128);
}

void duplicate_gesture_into_grid_R10(int grid_cell_size, int grid_size, int grid_padding)
{
	scamp5_kernel_begin();
	MOV(R10, R11);
	CLR(R1, R2, R3, R4);
	SET(R2);
		for (int n = 0; n < grid_size - 1; n++)
		{
			for (int x = 0; x < (grid_cell_size + grid_padding) / 2; x++)
			{
				DNEWS0(R9, R11);
				DNEWS0(R11, R9);
			}

			REFRESH(R11);
			OR(R2, R10, R11);
			MOV(R10, R2);
			SET(R2);
		}
	scamp5_kernel_end();

	//DO THE SECOND PART IN AREG SINCE THE DREG ON MY SCAMP ARE BAD... (comment preserved from the reference -- a real hardware quirk workaround, not a typo)
	scamp5_load_in(E, 0);
	scamp5_load_in(50);
	for (int i = 0; i < 7; i++)
	{
		scamp5_kernel_begin();
			mov(F, E);
			WHERE(R10);
				add(F, F, IN);
				add(F, F, IN);
				add(F, F, IN);
			all();

			for (int n = 0; n < grid_cell_size; n++)
			{
				mov(F, F, north);
			}

			sub(F, F, IN);

			where(F);
				OR(R1, FLAG, R10);
				MOV(R10, R1);
			all();
		scamp5_kernel_end();
	}
}
