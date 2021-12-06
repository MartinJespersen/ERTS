#include "pos_top_fixed.h"

void pos_top_start(fixed_point_t g[N])
{
#pragma HLS INTERFACE s_axilite port=g bundle=pos
#pragma HLS INTERFACE s_axilite port=return bundle=pos

    pos_algo_fixed pos_obj(g);
    pos_obj.pos_start(g);
}
