//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_PROXY_H
#define CLION_PROXY_H

#include "message_future.h"
#include "method_request.h"
#include "servant.h"
#include "scheduler.h"

class proxy
{
public:
    proxy(size_t size);
    message_future execute_pos_sw();
    message_future execute_pos_hw();
private:
    servant _servant;
    scheduler _scheduler;
};

#endif //CLION_PROXY_H
