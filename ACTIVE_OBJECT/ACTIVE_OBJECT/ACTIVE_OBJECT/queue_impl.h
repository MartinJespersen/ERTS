#pragma once
#include "method_request.h"
#include <list>
class queue_impl{
    public:
    queue_impl() = default;
    queue_impl(int max_size): _max_size(max_size){}

    virtual void put(method_request * m);
    virtual method_request * remove();
    virtual unsigned int size() const;
    virtual unsigned int get_max_size(); 
  
    ~queue_impl();
  protected:
    unsigned int _max_size;
};