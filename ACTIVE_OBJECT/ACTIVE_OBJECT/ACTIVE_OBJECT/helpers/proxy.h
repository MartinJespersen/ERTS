#pragma once
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


