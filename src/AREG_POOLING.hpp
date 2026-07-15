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
#include "MISC_FUNCTIONS.hpp"

using namespace SCAMP5_PE;

#ifndef AREG_POOLING
#define AREG_POOLING
// NOTE: AREG_POOLING is an empty object-like macro (this include guard), not
// a C++ namespace -- MAX_POOL_F is declared at global scope. Call sites that
// write `AREG_POOLING::MAX_POOL_F(...)` (e.g. MAIN_GESTURE_SINGLE_LAYER_16.cpp,
// matching the original reference repo verbatim) rely on this macro expanding
// to nothing, leaving `::MAX_POOL_F(...)` -- a global-scope-qualified call to
// the function declared below. Confirmed against the real reference repo:
// this is how the original code actually works, not a copy error.

void MAX_POOL_F(int iterations,bool maxpool_dirx, bool maxpool_diry,bool blocking);  //DESTROYS CONTENT IN R0

#endif
