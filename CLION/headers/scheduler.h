//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_SCHEDULER_H
#define CLION_SCHEDULER_H

#include "queue.h"
#include "pthread.h"

class scheduler{
public:
    scheduler(size_t size);
    void insert(method_request *mr);
protected:
    virtual void dispatch();
private:
    int _ret;
    queue _queue;
    pthread_t _thread;

    static void *svc_run(void *args);
};


#endif //CLION_SCHEDULER_H
