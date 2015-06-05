#ifndef __mutex_h
#define __mutex_h

#include <table_class_method.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_API

class Mutex {
public:
	Mutex() {
		mensagem = new Message();
    	mensagem->class_id(Class::MUTEX);
    	mensagem->method_id(Method::Mutex::CONSTRUCTOR);
    	Skeleton::call(mensagem);
    	_obj_id = mensagem->return_value();
	}
	
	~Mutex() {
		mensagem->class_id(Class::MUTEX);
    	mensagem->method_id(Method::Mutex::DESTRUCTOR);
    	mensagem->object_id(_obj_id);
    	Skeleton::call(mensagem);
		delete mensagem;
	}
	
	void lock() {
		mensagem->class_id(Class::MUTEX);
    	mensagem->method_id(Method::Mutex::LOCK);
    	mensagem->object_id(_obj_id);
    	Skeleton::call(mensagem);
	}
	
	void unlock() {
		mensagem->class_id(Class::MUTEX);
    	mensagem->method_id(Method::Mutex::UNLOCK);
    	mensagem->object_id(_obj_id);
    	Skeleton::call(mensagem);
	}
};
private:
	void * _obj_id;
	Message * mensagem;
};

__END_API
#endif
