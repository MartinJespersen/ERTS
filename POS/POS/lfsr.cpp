#include "lfsr.h"

double lfsr::uniform_random(double from, double to)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist6(from, to);
    return dist6(rng);
}
