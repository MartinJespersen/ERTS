#include "method_request.h"

/*     BY SOFTWARE     */
get_by_software::get_by_software(servant * servant, const message_future &f) :
    _servant(servant),
    _result(f)
{
	
}

bool get_by_software::can_run() const
{
	return !_servant->is_running(); 
}

void get_by_software::call() 
{
	_result = message_future(_servant->get_global_best<system_type::SOFTWARE>()); 
}

/*     BY HARDWARE     */
get_by_hardware::get_by_hardware(servant * servant, const message_future &f) : 
    _servant(servant),
    _result(f) 
{
	
}

bool get_by_hardware::can_run() const
{
	return !_servant->is_running(); 
}

void get_by_hardware::call() 
{
	_result = message_future(_servant->get_global_best<system_type::HARDWARE>()); 
}