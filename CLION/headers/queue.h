//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_QUEUE_H
#define CLION_QUEUE_H

#include <pthread.h>
#include "method_request.h"
#include "queue_impl.h"
#include "queue_win.h"

class queue{
public:
    queue(size_t size);
    void put(method_request* mes);
    method_request* remove();
private:
    queue_impl * _impl;
    pthread_mutex_t _mut;
    int ret;
    pthread_cond_t _writer_cond, _reader_cond;
};

#endif //CLION_QUEUE_H
