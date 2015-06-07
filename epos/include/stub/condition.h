#ifndef __address_space_h
#define __address_space_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Condition {

public:

    Condition() {
		message = new Message();
    	message->class_id(Class::CONDITION);
    	message->method_id(Method::Condition::CONSTRUCTOR);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    };
	
    ~Condition(){
    	message->class_id(Class::CONDITION);
    	message->method_id(Method::Condition::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
    };

    void wait() {
    	message->class_id(Class::CONDITION);
    	message->method_id(Method::Condition::WAIT);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
    };

    void signal(){
    	message->class_id(Class::CONDITION);
    	message->method_id(Method::Condition::SIGNAL);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
    };
	
	void broadcast(){
    	message->class_id(Class::CONDITION);
    	message->method_id(Method::Condition::BROADCAST);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
    };
	
private:
   void * _obj_id;
   Message * message;
};

__END_APP
#endif