#pragma once
#include <random>

// Inspiration from: https://highlevel-synthesis.com/2017/02/10/lfsr-in-hls/
class lfsr
{
public:
	double generate_random(double from, double to); 
private:
	unsigned int pseudo_random(unsigned int seed, int load);
	double uniform_random(double from, double to); 
};

