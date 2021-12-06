//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_QUEUE_IMPL_H
#define CLION_QUEUE_IMPL_H

#include "method_request.h"
#include <list>
class queue_impl{
public:

    virtual void put(method_request * m) = 0;
    virtual method_request * remove() = 0;
    virtual size_t size() const = 0;
    virtual size_t get_max_size() = 0;
};

#endif //CLION_QUEUE_IMPL_H
