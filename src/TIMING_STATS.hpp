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
#include <list>
#include <algorithm>
#include "REGISTER_ENUMS.hpp"
using namespace SCAMP5_PE;

namespace TIMING_STATS
{
	void print_and_clear(bool clear_text_console);
	extern bool enabled;
}

void tick(std::string nametag,int samples);

void tick(std::string nametag);

void tock();

void tick_frame();

void tock_frame();
