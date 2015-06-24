#ifndef __stub_mutex_h
#define __stub_mutex_h

#include <api_types.h>
#include <stub/stub.h>

__BEGIN_APPLICATION

class Mutex : Stub
{
friend class Mutex_Handler;
public:
    Mutex(){
        int * message = new int[4] {Class::MUTEX, Method::Mutex::CONSTRUCTOR, 0, 0};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Mutex(){
       int * message = new int[3] {Class::MUTEX, Method::Mutex::DESTRUCTOR, _object_id};
       syscall(message);
       delete message;
    }

    void lock(){
        int * message = new int[3] {Class::MUTEX, Method::Mutex::LOCK, _object_id};
        syscall(message);
        delete message;
    }

    void unlock(){
      int * message = new int[3] {Class::MUTEX, Method::Mutex::UNLOCK, _object_id};
      syscall(message);
      delete message;
    }

private:
    int _object_id;
};


class Mutex_Handler:public Handler, Stub
{
public:
    Mutex_Handler(Mutex * mutex){
        int imutex = mutex->_object_id;
        int * message = new int[5] {Class::MUTEX_HANDLER, Method::Handler::CONSTRUCTOR, 0, 0, imutex};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Mutex_Handler(){
        int * message = new int[4] {Class::MUTEX_HANDLER, Method::Handler::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    void operator ()(){
        int * message = new int[4] {Class::MUTEX_HANDLER, Method::Handler::CALL, _object_id, 0};
        syscall(message);
        delete message;
    }

private:
    int _object_id;
};

__END_APPLICATION

#endif
