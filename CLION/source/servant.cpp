//
// Created by Trill on 06-12-2021.
//

#include "../headers/servant.h"
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif


const bool servant::is_running() const
{
    // TODO: Create logic that checks if hardware is ready.
    return false;
}


message servant::get_global_best_sw()
{
    std::cout << __func__ << std::endl;
    float i[N] = {1,1};
    return message(i);
}


message servant::get_global_best_hw()
{
    sleep(5);
    std::cout << __func__ << std::endl;
    float i[N] = {1,1};
    return message(i);
}