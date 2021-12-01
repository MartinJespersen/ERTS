#pragma once
#include "message_future.h"
#include "servant.h"

class method_request
{
public:
	virtual bool can_run() const = 0;
	virtual void call() = 0;
};

class get_by_software : public method_request {
public: 
	get_by_software(servant * servant, const message_future &f);
	virtual bool can_run() const; 
	virtual void call(); 

private: 
	servant * _servant; 
	message_future _result; 
};

class get_by_hardware : public method_request {
public: 
	get_by_hardware(servant * servant, const message_future &f);
	virtual bool can_run() const; 
	virtual void call(); 

private: 
	servant * _servant; 
	message_future _result; 
};