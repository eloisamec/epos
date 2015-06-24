#ifndef __stub_condition_h
#define __stub_condition_h

#include <api_types.h>
#include <stub/stub.h>

__BEGIN_APPLICATION

class Condition : Stub
{

public:

    Condition(){
        int * message = new int[4] {Class::CONDITION, Method::Condition::CONSTRUCTOR, 0, 0};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Condition(){
        int * message = new int[4] {Class::CONDITION, Method::Condition::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    void wait(){
        int * message = new int[4] {Class::CONDITION, Method::Condition::WAIT, _object_id, 0};
        syscall(message);
        delete message;
    }

    void signal(){
        int * message = new int[4] {Class::CONDITION, Method::Condition::_SIGNAL, _object_id, 0};
        syscall(message);
        delete message;
    }

    void broadcast(){
        int * message = new int[4] {Class::CONDITION, Method::Condition::BROADCAST, _object_id, 0};
        syscall(message);
        delete message;
    }

private:
    int _object_id;
};



class Condition_Handler: public Handler, Stub
{

public:

    Condition_Handler(Condition * condition){
        int icondition = condition->_object_id;
        int * message = new int[5] {Class::CONDITION_HANDLER, Method::Handler::CONSTRUCTOR, 0, 0, icondition};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Condition_Handler(){
        int * message = new int[4] {Class::CONDITION_HANDLER, Method::Handler::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    void operator()(){
        int * message = new int[4] {Class::CONDITION_HANDLER, Method::Handler::CALL, _object_id, 0};
        syscall(message);
        delete message;
    }


private:
    int _object_id;
};

__END_APPLICATION

#endif
