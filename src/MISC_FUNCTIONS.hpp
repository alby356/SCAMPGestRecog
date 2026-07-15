// ---------------------------------------------------------------------------
// Copied verbatim from github.com/lauriebose/Scamp5-MNIST_AREG_CNN_example
// (the paper's own reference implementation of arXiv:2004.12525). Generic /
// filter-count and block-size agnostic -- no gesture-specific changes needed.
// NOT compiled or run in this environment (no SCAMP5 SDK/simulator/hardware
// available here); ported for correctness against the real API, unverified
// against real hardware.
// ---------------------------------------------------------------------------
//Author: Laurie Bose
//Date: 2021

#include <scamp5.hpp>
#include <math.h>
#include "REGISTER_ENUMS.hpp"

using namespace SCAMP5_PE;

#ifndef MISC_FUNCTIONS
#define MISC_FUNCTIONS
	unsigned char reverse_byte(unsigned char x);
	double sin_approx3(double angle);
	double cos_approx3(double angle);
	double acos_approx3(double value);
	double tan_approx3(double angle);

	void SETUP_SHIFT_R11_USING_AREG_EF(bool black_boundaries);

	void SHIFTx1_R11_USING_AREG_EF(int shift_x, int shift_y, bool perform_shift_setup = true, bool setup_shift_for_black_borders = true);
	void SHIFTx1_R11_USING_AREG_EF_NORTH();
	void SHIFTx1_R11_USING_AREG_EF_SOUTH();
	void SHIFTx1_R11_USING_AREG_EF_EAST();
	void SHIFTx1_R11_USING_AREG_EF_WEST();

	void SHIFTx4_R11_USING_AREG_EF(int shift_x, int shift_y, bool perform_shift_setup = true, bool setup_shift_for_black_borders = true);
	void SHIFTx4_R11_USING_AREG_EF_NORTH();
	void SHIFTx4_R11_USING_AREG_EF_SOUTH();
	void SHIFTx4_R11_USING_AREG_EF_EAST();
	void SHIFTx4_R11_USING_AREG_EF_WEST();

	void copy_dreg(DENUM target,DENUM source);

	void copy_dreg_into_R11(DENUM reg);
	void copy_R11_into_dreg(DENUM reg);

	void copy_areg_into_F(AENUM reg);
	void copy_F_into_areg(AENUM reg);

	void shift_R11(int x, int y);
	void shift_dreg(DENUM reg,int x, int y);

	void load_rect_into_DREG(DENUM reg,int x,int y,int w,int h);
	void load_centered_rect_into_DREG(DENUM reg,int x,int y,int w,int h);

	void load_DREG_into_F(DENUM reg,int white_value = 127,int black_value = -127);

	void draw_16_segment_display_to_R11(int width,int height,int thickness,bool segment_toggles[16]);
	void draw_16_segment_digit_to_R11(int width,int height,int thickness,int digit);

	void acquire_edge_image_R10(int gain,int edge_thresold, int edge_expansion,int HDR_iterations, int HDR_exposure_time);

	// DREG_SUM_R10(), DREG_SUM_R10_STEVE_OPT(), DREG_STACKING_R10_INTO_R1_STEVE_OPT()
	// removed -- see the matching comment in MISC_FUNCTIONS.cpp (they don't compile
	// against the installed SDK's digital macro API and aren't used by this project).

#endif
