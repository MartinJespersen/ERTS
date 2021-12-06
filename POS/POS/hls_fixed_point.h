#pragma once
#include "ap_fixed.h"
#include "ap_cint.h"

// Vivado HLS creates hardware in which a 32-bit multiplier result is sign-extended to a 36-bit result.
#define FIXED_SIZE 32
#define FIXED_BITS_FRACT 8
#define FIXED_MAX 0xFFFF;

typedef ap_fixed< FIXED_SIZE, FIXED_SIZE-FIXED_BITS_FRACT > fixed_point_t;

typedef int18 din_t;
