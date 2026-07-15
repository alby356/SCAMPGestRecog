// ---------------------------------------------------------------------------
// Adapted from FUNCS_DIGIT_EXTRACTION.hpp in
// github.com/lauriebose/Scamp5-MNIST_AREG_CNN_example (the paper's own
// reference implementation of arXiv:2004.12525).
//
// duplicate_gesture_into_grid_R10 is an unmodified rename (see below) --
// tiling a silhouette into a grid has no digit-specific logic.
//
// extract_gesture_blob_from_F_into_R11 started as a rename of the
// reference's extract_character_from_F_into_R11, but its flood-fill blob
// isolation (seeded from a FIXED small rectangle assumed to overlap a
// centered handwritten digit) was removed after real-hardware testing showed
// it produced an all-black duplicated image whenever the hand didn't happen
// to overlap that seed box. The threshold -> center -> scale-to-fill
// pipeline is otherwise the same proven logic, just operating on the raw
// threshold result directly instead of a flood-fill-isolated blob -- see the
// comment in GESTURE_CAPTURE.cpp for the full reasoning.
//
// NOT compiled or run in this environment (no SCAMP5 SDK/simulator here);
// the flood-fill-removal fix above was diagnosed from a screenshot of real
// hardware output relayed by the user, not verified directly.
// ---------------------------------------------------------------------------

#include <scamp5.hpp>

// Threshold F (the captured camera frame) against `threshold`, center the
// thresholded region, and scale it to fill a `size` x `size` box -- result
// left in R11 as a binary silhouette DREG. white_on_black_blob=true matches
// HandGestures (bright hand, dark background), unlike the reference's
// dark-digit-on-white-page default.
void extract_gesture_blob_from_F_into_R11(bool white_on_black_blob, int threshold, int size, int xpos, int ypos);

// Tile whatever binary silhouette is currently in R11 into an
// grid_size x grid_size grid of grid_cell_size x grid_cell_size blocks,
// result in R10. Direct rename of duplicate_digit_into_grid_R10 -- the
// routine only ever reads R11 and writes a tiled copy to R10, it has no
// digit-specific logic.
void duplicate_gesture_into_grid_R10(int grid_cell_size, int grid_size, int grid_padding);
