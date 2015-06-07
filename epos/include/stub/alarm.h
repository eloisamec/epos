#ifndef __alarm_h
#define __alarm_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Alarm {
	
public:

    Alarm(const Microsecond &time, Handler * handler, int times = 1) {
		message = new Message();
    	message->class_id(Class::ALARM);
    	message->method_id(Method::Alarm::CONSTRUCTOR);
		message->param1((void*) &time);
		message->param2((void*) &handler);
		message->param3((void*) &times);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    };
	
	~Alarm(){
    	message->class_id(Class::ALARM);
    	message->method_id(Method::Alarm::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
    };

    static Hertz frequency() {
		Message message = Message();
    	message.class_id(Class::ALARM);
    	message.method_id(Method::Alarm::FREQUENCY);
    	Skeleton::call(&message);
		Hertz frequency = reinterpret_cast<Hertz> (message.return_value());
		return frequency;
    };

	static void delay(const Microsecond & time) {
		Message message = Message();
    	message.class_id(Class::ALARM);
    	message.method_id(Method::Alarm::DELAY);
    	Skeleton::call(&message);
    };
	
private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif