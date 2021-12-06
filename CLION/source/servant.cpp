//
// Created by Trill on 06-12-2021.
//

#include "../headers/servant.h"

const bool servant::is_running() const
{
    // TODO: Create logic that checks if hardware is ready.
    return false;
}


message servant::get_global_best_sw()
{
    std::cout << __func__ << std::endl;
    float i[2] = {1,1};
    return message(i);
}


message servant::get_global_best_hw()
{
    std::cout << __func__ << std::endl;
    float i[2] = {1,1};
    return message(i);
}