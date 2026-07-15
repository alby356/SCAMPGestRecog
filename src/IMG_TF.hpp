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

using namespace SCAMP5_PE;

#include "IMG_SCALING_DIGITAL.hpp"

#ifndef IMG_TF
#define IMG_TF
namespace IMGTF
{
	unsigned char reverse_byte(unsigned char x);
	double sin_approx3(double angle);
	double cos_approx3(double angle);
	double acos_approx3(double value);
	double tan_approx3(double angle);
}
#endif



