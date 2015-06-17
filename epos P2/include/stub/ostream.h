#ifndef __ostream_h
#define __ostream_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class OStream {
	
private:
    struct Begl {};
    struct Endl {};
    struct Hex {};
    struct Dec {};
    struct Oct {};
    struct Bin {};
    struct Err {};

public:
    OStream() {
		message = new Message();
    	message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::CONSTRUCTOR);
		Skeleton::call(message);
    	_obj_id = message->return_value();
	}

    OStream & operator<<(const Begl & begl) {
		message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_1);
		message->param1(begl);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    
    OStream & operator<<(const Endl & endl) {
       message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_3);
		message->param1(endl);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(const Hex & hex) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_4);
		message->param1(hex);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    
	OStream & operator<<(const Dec & dec) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_5);
		message->param1(dec);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    
	OStream & operator<<(const Oct & oct) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_6);
		message->param1(oct);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    
	OStream & operator<<(const Bin & bin) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_7);
		message->param1(bin);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(const Err & err) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_8);
		message->param1(err);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(char c) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_9);
		message->param1(c);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    OStream & operator<<(unsigned char c) { 
		message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_10);
		message->param1(c);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(int i) {
		message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_11);
		message->param1(i);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    OStream & operator<<(short s) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_12);
		message->param1(s);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    OStream & operator<<(long l) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_13);
		message->param1(l);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(unsigned int u) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_14);
		message->param1(u);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    OStream & operator<<(unsigned short s) { 
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_15);
		message->param1(s);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
    OStream & operator<<(unsigned long l) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_16);
		message->param1(l);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(long long int u) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_17);
		message->param1(u);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(unsigned long long int u) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_18);
		message->param1(u);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(const void * p) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_19);
		message->param1(p);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(const char * s) { 
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_20);
		message->param1(s);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }

    OStream & operator<<(float f) {
        message->class_id(Class::OSTREAM);
    	message->method_id(Method::OStream::OPERATOR_21);
		message->param1(f);
    	Skeleton::call(message);
		_obj_id = message->return_value();
    }
	
private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif