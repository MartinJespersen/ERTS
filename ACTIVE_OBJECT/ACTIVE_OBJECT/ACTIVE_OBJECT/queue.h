#pragma once
#include <pthread.h>
#include "method_request.h"
#include "queue_impl.h"
class queue{
public:
    queue(size_t size);
    void put(method_request* mes);
    method_request* remove();

private:
    queue_impl _impl;
    pthread_mutex_t _mut;
    int ret;
    pthread_cond_t _writer_cond, _reader_cond;

};