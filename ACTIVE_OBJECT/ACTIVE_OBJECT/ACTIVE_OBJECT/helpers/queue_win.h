#pragma once 

#include "method_request.h"
#include "queue_impl.h"
#include <deque>
class queue_win: public queue_impl{
public:
    queue_win(size_t max_size);
    void put(method_request * m) override;
    method_request * remove() override;
    size_t size() const override;
    size_t get_max_size() override; 
private:
    std::deque<method_request *> _queue;
    size_t _max_size;
};