#ifndef __display_h
#define __display_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Display {

public:
	Display() {
		message = new Message();
		message->class_id(Class::DISPLAY);
    	message->method_id(Method::Display::CONSTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}

    static void clear() {
    	Message message = Message();
    	message.class_id(Class::DISPLAY);
    	message.method_id(Method::Display::CLEAR);
    	Skeleton::call(&message);
    }

	static void putc() {
		Message message = Message();
    	message.class_id(Class::DISPLAY);
    	message.method_id(Method::Display::PUTC);
    	Skeleton::call(&message);
    }
	
	static void puts(const char * s) {
		Message message = Message();
    	message.class_id(Class::DISPLAY);
    	message.method_id(Method::Display::PUTS);
    	message.param1((void*) s);
    	Skeleton::call(&message);
	}
	
	static void geometry(int * lines, int * columns) {
		Message message = Message();
    	message.class_id(Class::DISPLAY);
    	message.method_id(Method::Display::GEOMETRY);
    	message.param1((void*) &lines);
		message.param2((void*) &columns);
    	Skeleton::call(&message);
    }
	
	static void position(int * line, int * column) {
		Message message = Message();
    	message.class_id(Class::DISPLAY);
    	message.method_id(Method::Display::POSITION_1);
    	message.param1((void*) &line);
		message.param2((void*) &column);
    	Skeleton::call(&message);
    }
	
	static void position(int line, int column) {
		Message message = Message();
    	message.class_id(Class::DISPLAY);
    	message.method_id(Method::Display::POSITION_2);
    	message.param1((void*) line);
		message.param2((void*) column);
    	Skeleton::call(&message);
    }

private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif
