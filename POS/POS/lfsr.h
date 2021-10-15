#pragma once
#include <random>
#include "fixed_point.h"

// Inspiration from: https://highlevel-synthesis.com/2017/02/10/lfsr-in-hls/
class lfsr
{
public:
	unsigned int pseudo_random(unsigned int seed);
	double uniform_random(double from, double to); 
};

