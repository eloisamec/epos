#ifndef __semaphore_h
#define __semaphore_h

#include <table_class_method.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_API

class Semaphore {
public:
    Semaphore(int v = 1){
		mensagem = new Message();
    	mensagem->class_id(Class::SEMAPHORE);
    	mensagem->method_id(Method::Semaphore::CONSTRUCTOR);
    	mensagem->param1((void*) &v);
    	Skeleton::call(mensagem);
    	_obj_id = mensagem->return_value();
    };
	
    ~Semaphore(){
    	mensagem->class_id(Class::SEMAPHORE);
    	mensagem->method_id(Method::Semaphore::DESTRUCTOR);
    	mensagem->object_id(_obj_id);
    	Skeleton::call(mensagem);
		delete mensagem;
    };

    void p(){
    	mensagem->class_id(Class::SEMAPHORE);
    	mensagem->method_id(Method::Semaphore::P);
    	mensagem->object_id(_obj_id);
    	Skeleton::call(mensagem);
    };

    void v(){
    	mensagem->class_id(Class::SEMAPHORE);
    	mensagem->method_id(Method::Semaphore::V);
    	mensagem->object_id(_obj_id);
    	Skeleton::call(mensagem);
    };

private:
	void * _obj_id;
	Message * mensagem;
};

__END_API
#endif