#include "scheduler.h"
#include "pthread.h"
scheduler::scheduler(size_t size)
{
    _queue = new queue(size);
    _ret = pthread_create(&_thread, NULL, svc_run, (void*)this);
}

static void * scheduler::svc_run(void *args) {
    scheduler *this_obj = static_cast<scheduler *> (args);
    this_obj->dispatch(); // equal to a thread run method
}

void scheduler::insert(method_request *mr) { 
    _queue->put(mr); 
}

void scheduler::dispatch(){
    while(1){
        method_request * request = _queue->remove();
        if ( (*request).can_run() )
        {
            _queue->remove(*request);
            (*request).call();
            delete *request;
        }
    }
}