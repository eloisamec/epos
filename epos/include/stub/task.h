#ifndef __task_h
#define __task_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Task {

public:

    Task(const Segment &cs, const Segment &ds) {
		message = new Message();
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::CONSTRUCTOR);
    	message->param1((void*) &cs);
    	message->param2((void*) &ds);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    }
	
    ~Task(){
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
    }

    Address_Space * address_space() {
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::ADDRESS_SPACE);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Address_Space * address_space = reinterpret_cast<Address_Space *>(message->return_value());
		return address_space;
    }

    const Segment * code_segment(){
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::CODE_SEGMENT);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Segment * cs = reinterpret_cast<Segment *>(message->return_value());
		return cs;
    }
	
	const Segment * data_segment(){
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::DATA_SEGMENT);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Segment * ds = reinterpret_cast<Segment *>(message->return_value());
		return ds;
    }
	
	Log_Addr code(){
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::CODE);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Log_Addr code = reinterpret_cast<Log_Addr*>(message->return_value());
		return code;
    }
	
	
	Log_Addr data(){
    	message->class_id(Class::TASK);
    	message->method_id(Method::Task::DATA);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Log_Addr data = reinterpret_cast<Log_Addr*>(message->return_value());
		return data;
    }

	static Task * self() {
		Message message = Message();
		message.class_id(Class::TASK);
    	message.method_id(Method::Task::SELF);
    	Skeleton::call(&message);
		Task * task = reinterpret_cast<Task *>(message.return_value());
		return task;
	}

private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif
