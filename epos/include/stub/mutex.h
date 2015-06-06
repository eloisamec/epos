#ifndef __mutex_h
#define __mutex_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_API

class Mutex {

public:
	Mutex() {
		message = new Message();
    	message->class_id(Class::MUTEX);
    	message->method_id(Method::Mutex::CONSTRUCTOR);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	~Mutex() {
		message->class_id(Class::MUTEX);
    	message->method_id(Method::Mutex::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
	}
	
	void lock() {
		message->class_id(Class::MUTEX);
    	message->method_id(Method::Mutex::LOCK);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
	void unlock() {
		message->class_id(Class::MUTEX);
    	message->method_id(Method::Mutex::UNLOCK);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
private:
	void * _obj_id;
	Message * message;
};

__END_API
#endif
