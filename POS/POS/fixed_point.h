#pragma once
#include <cmath>
#include <limits>
// Inspired by: https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
// Q16.15 (1 signed bit)
#define FIXED_FRACT_BITS 15
#define MAX 0x7FFFFFFF
#define MIN 0x80000000
typedef __int32 fixed_point_t;
typedef __int64 fixed_point_merger_t;

static fixed_point_merger_t merger; 

float fixed_to_float(fixed_point_t a); 
fixed_point_t fixed_add(fixed_point_t a, fixed_point_t b);
fixed_point_t fixed_multiply(fixed_point_t a, fixed_point_t b);
fixed_point_t fixed_division(fixed_point_t a, fixed_point_t b); 
