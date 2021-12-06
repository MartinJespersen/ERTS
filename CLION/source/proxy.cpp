//
// Created by Trill on 06-12-2021.
//

#include "../headers/proxy.h"

proxy::proxy(size_t size): _scheduler(size){}

message_future proxy::execute_pos_sw()
{
    message_future result;
    method_request * mr = new get_by_software(&_servant, result);
    _scheduler.insert(mr);
    return result;
}

message_future proxy::execute_pos_hw()
{
    message_future result;
    method_request * mr = new get_by_hardware(&_servant, result);
    _scheduler.insert(mr);
    return result;
}