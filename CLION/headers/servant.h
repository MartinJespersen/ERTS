//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_SERVANT_H
#define CLION_SERVANT_H

#include "message.h"
#include <iostream>

enum class system_type { SOFTWARE, HARDWARE };

class servant
{
public:
    const bool is_running() const;

    message get_global_best_hw();
    message get_global_best_sw();
};


#endif //CLION_SERVANT_H
