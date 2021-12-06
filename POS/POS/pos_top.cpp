#include "pos_top.h"

void pos_top_start(float g[N])
{
#pragma HLS INTERFACE s_axilite port=g bundle=pos

    pos_algo pos_obj(g);
    pos_obj.pos_start(g); 
}
