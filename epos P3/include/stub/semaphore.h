#ifndef __stub_semaphore_h
#define __stub_semaphore_h

#include <api_types.h>

__BEGIN_APPLICATION

class Semaphore : Stub
{

public:
Semaphore(int v = 1){
    int * message = new int[5]{Class::SEMAPHORE, Method::Semaphore::CONSTRUCTOR, 0, 0, v};
    syscall(message);
    _object_id = message[2];
    delete message;
}

~Semaphore(){
    int * message = new int[4] {Class::SEMAPHORE, Method::Semaphore::DESTRUCTOR, _object_id, 0};
    syscall(message);
    delete message;
}

void p(){
    int * message = new int[4] {Class::SEMAPHORE, Method::Semaphore::P, _object_id, 0};
    syscall(message);
    delete message;
}

void v(){
    int * message = new int[4] {Class::SEMAPHORE, Method::Semaphore::V, _object_id, 0};
    syscall(message);
    delete message;
}

private:
    int _object_id;
};


class Semaphore_Handler : public Handler, Stub
{
public:
    Semaphore_Handler(Semaphore * semaphore){
        int isemaphore= semaphore->_object_id;
        int * message = new int[5] {Class::SEMAPHORE_HANDLER, Method::Handler::CONSTRUCTOR, 0, 0, isemaphore};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Semaphore_Handler(){
        int * message = new int[4] {Class::SEMAPHORE_HANDLER, Method::Handler::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    void operator()(){
        int * message = new int[4] {Class::SEMAPHORE_HANDLER, Method::Handler::CALL, _object_id, 0};
        syscall(message);
        delete message;
    }


private:
    int _object_id;
};

__END_APPLICATION

#endif
