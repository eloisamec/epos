// EPOS Semaphore Abstraction Declarations

#ifndef __semaphore_h
#define __semaphore_h

#include <synchronizer.h>
#include <utility/handler.h>

__BEGIN_SYS

class Semaphore: protected Synchronizer_Common
{
public:
    Semaphore(int v = 1);
    ~Semaphore();

    void p();
    void v();

private:
    volatile int _value;
};

class Semaphore_Handler : public Handler
{
public:
    Semaphore_Handler(Semaphore * h) : _handler(h) {};
    ~Semaphore_Handler() {};

    void operator()() { _handler->v(); }
	
private:
    Semaphore * _handler;
};
__END_SYS

#endif
