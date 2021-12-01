#pragma once
#include "queue.h"

class scheduler{
public:
    scheduler(size_t size);
    void insert(method_request *mr);
protected:
    virtual void dispatch();
private:
    int _ret;
    queue * _queue;
    pthread_t _thread;

    static void *svc_run(void *args);
};