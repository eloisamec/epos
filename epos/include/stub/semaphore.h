#ifndef __semaphore_h
#define __semaphore_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_API

class Semaphore {

public:
    Semaphore(int v = 1){
		message = new Message();
    	message->class_id(Class::SEMAPHORE);
    	message->method_id(Method::Semaphore::CONSTRUCTOR);
    	message->param1((void*) &v);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    };
	
    ~Semaphore(){
    	message->class_id(Class::SEMAPHORE);
    	message->method_id(Method::Semaphore::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
    };

    void p(){
    	message->class_id(Class::SEMAPHORE);
    	message->method_id(Method::Semaphore::P);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
    };

    void v(){
    	message->class_id(Class::SEMAPHORE);
    	message->method_id(Method::Semaphore::V);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
    };

private:
	void * _obj_id;
	Message * message;
};

__END_API
#endif