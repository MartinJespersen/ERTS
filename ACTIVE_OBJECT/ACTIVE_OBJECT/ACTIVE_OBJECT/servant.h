#pragma once
#include "message.h"
#include <iostream> 

enum class system_type { SOFTWARE, HARDWARE }; 

class servant
{
public: 
    servant(); 
    const bool is_running() const; 

    template<system_type system_type>  
    message get_global_best(); 
};

const bool servant::is_running() const
{
    // TODO: Create logic that checks if hardware is ready. 
    return false; 
}

template<>
message servant::get_global_best<system_type::SOFTWARE> ()
{
    std::cout << __func__ << std::endl; 
}

template <> 
message servant::get_global_best<system_type::HARDWARE> ()
{
    std::cout << __func__ << std::endl;     
}