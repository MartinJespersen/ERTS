#include "lfsr.h"
// Inspiration from: https://en.wikipedia.org/wiki/Linear-feedback_shift_register
unsigned int lfsr::pseudo_random(unsigned int seed)
{
    uint16_t start_state = seed;  /* Any nonzero start state will work. */
    uint16_t lfsr = start_state;
    uint16_t bit;                    /* Must be 16-bit to allow bit<<15 later in the code */
    unsigned period = 0;

    do
    {   /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
        bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1u;
        lfsr = (lfsr >> 1) | (bit << 15);
        ++period;
    } while (lfsr != start_state);

    return period;
}

double lfsr::uniform_random(double from, double to)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist6(from, to);
    return dist6(rng);
}
