#include "pos_top_fixed.h"
//#define __float__

int main()
{
#if defined(__float__)
    float g[N];
    pos_top_start(g);
#else 
    fixed_point_t g[N];
    pos_top_start(g);
#endif 
};

