// API Handler

#ifndef __handler_h
#define __handler_h

#include <api_types.h>
#include <stub/stub.h>

__BEGIN_API

class Handler : Stub
{
public:
    // A handler function
    typedef void (Function)();

public:
    Handler() {}
    virtual ~Handler() {}

    virtual void operator()() = 0;
};

class Function_Handler: public Handler
{
public:
    Function_Handler(Function * h):{
        message = new Message();
        message->class_id(Class::FUNCTION_HANDLER);
        message->method_id(Method::Function_Handler::CONSTRUCTOR);
        message->param1((void*) h);
        syscall(message);
        _object_id = message->return_value();

    };
    ~Function_Handler() {
        message->class_id(Class::FUNCTION_HANDLER);
        message->method_id(Method::Function_Handler::DESTRUCTOR);
        message->object_id(_object_id);
        syscall(message);
    };

    void call() {
        message->class_id(Class::FUNCTION_HANDLER);
        message->method_id(Method::Function_Handler::CALL);
        message->object_id(_object_id);
        syscall(message);
    };

};

//template<typename T>
//class Functor_Handler: public Handler
//{
//public:
//    typedef void (Functor)(T *);

//    Functor_Handler(Functor * h, T * p){
//        message = new Message();
//        message->class_id(Class::FUNCTOR_HANDLER);
//        message->method_id(Method::Functor_Handler::CONSTRUCTOR);
//        message->param1((void*) h);
//        message->param2((void*) p);
//        syscall(message);
//        _object_id = message->return_value();
//    };

//    ~Functor_Handler() {
//        message->class_id(Class::FUNCTOR_HANDLER);
//        message->method_id(Method::Functor_Handler::DESTRUCTOR);
//        message->object_id(_object_id);
//        syscall(message);
//    };

//    void call() {
//        message->class_id(Class::FUNCTOR_HANDLER);
//        message->method_id(Method::Functor_Handler::CALL);
//        message->object_id(_object_id);
//        syscall(message);
//    };

//};

__END_API

#endif

