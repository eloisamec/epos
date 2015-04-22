// EPOS Synchronizer Abstractions Common Package

#ifndef __synchronizer_h
#define __synchronizer_h

#include <cpu.h>
#include <thread.h>

__BEGIN_SYS

class Synchronizer_Common
{
protected:
    Synchronizer_Common() {}
	~Synchronizer_Common() 
	{
		begin_atomic();
		wakeup_all();
		end_atomic();
	}
	
    // Atomic operations
    bool tsl(volatile bool & lock) { return CPU::tsl(lock); }
    int finc(volatile int & number) { return CPU::finc(number); }
    int fdec(volatile int & number) { return CPU::fdec(number); }

    // Thread operations
    void begin_atomic() { Thread::lock(); }
    void end_atomic() { Thread::unlock(); }

    void sleep() 
    { 
		Thread::running()->suspend();
    } // implicit unlock()
    void wakeup() 
    { 
		if(!Thread::_suspended.empty()) 
		{
			Thread::_suspended.head()->object()->resume();
		}
    }
    void wakeup_all()
    { 
		while(!Thread::_suspended.empty())
		{
			Thread::_suspended.head()->object()->resume();
		}
    }
};

__END_SYS

#endif
