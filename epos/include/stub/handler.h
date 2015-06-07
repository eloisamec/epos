#ifndef __handler_h
#define __handler_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Function_Handler {

public:
	Function_Handler(Function * h) {
		message = new Message();
		message->class_id(Class::HANDLER);
		message->method_id(Method::Handler::CONSTRUCTOR);
		message->param1((void*) h);
		Skeleton::call(message);
		_obj_id = message->return_value();
	}

	~Function_Handler(){
		message->class_id(Class::HANDLER);
		message->object_id(_obj_id);
		Skeleton::call(message);
		delete message;
	}

private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif
