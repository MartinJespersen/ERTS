//
// Created by Trill on 06-12-2021.
//

#include "../headers/scheduler.h"

scheduler::scheduler(size_t size): _queue(size)
{
    _ret = pthread_create(&_thread, NULL, svc_run, (void*)this);
}

void * scheduler::svc_run(void *args) {
    scheduler *this_obj = static_cast<scheduler*> (args);
    this_obj->dispatch();
}

void scheduler::insert(method_request *mr) {
    _queue.put(mr);
}

void scheduler::dispatch(){
    while(1){
        method_request * request = _queue.remove();
        if ( request->can_run() )
        {
            request->call();
            delete request;
        }
        else{
            _queue.put(request);
        }
    }
}

void scheduler::join() {
    pthread_join(_thread, NULL);
}
