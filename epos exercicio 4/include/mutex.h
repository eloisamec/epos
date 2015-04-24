// EPOS Mutex Abstraction Declarations

#ifndef __mutex_h
#define __mutex_h

#include <synchronizer.h>
#include <utility/handler.h>

__BEGIN_SYS

class Mutex: protected Synchronizer_Common
{
public:
    Mutex();
    ~Mutex();

    void lock();
    void unlock();

private:
    volatile bool _locked;
};

class Mutex_Handler: public Handler
{
public:
    Mutex_Handler(Mutex * h) : _handler(h) {};
    ~Mutex_Handler() {};

    void operator()() { _handler->unlock(); }
	
private:
    Mutex * _handler;
};

__END_SYS

#endif
