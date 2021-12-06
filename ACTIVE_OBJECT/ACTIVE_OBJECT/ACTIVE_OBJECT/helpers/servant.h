#pragma once
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

