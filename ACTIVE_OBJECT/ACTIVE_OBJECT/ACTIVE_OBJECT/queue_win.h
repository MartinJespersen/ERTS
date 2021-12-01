#pragma once 

#include "method_request.h"
#include "queue_impl.h"
#include <deque>
class queue_win: public queue_impl{
public:
    void put(method_request * m) override;
    method_request * remove() override;
    unsigned int size() const override;
    unsigned int get_max_size() override; 
private:
    std::deque<method_request *> _queue;
};