#ifndef __thread_h
#define __thread_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_API

class Thread {

public:
	Thread() {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	~Thread() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
	}
	
	void lock() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::LOCK);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
	void unlock() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::UNLOCK);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
private:
	void * _obj_id;
	Message * message;
};

__END_API
#endif
