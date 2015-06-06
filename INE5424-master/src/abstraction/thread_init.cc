// EPOS Thread Abstraction Initialization

#include <system.h>
#include <thread.h>
#include <alarm.h>
#include <task.h>

extern "C" { void __epos_app_entry(); }

__BEGIN_SYS

void Thread::init()
{
    // If EPOS is a library, then adjust the application entry point to __epos_app_entry,
    // which will directly call main(). In this case, _init will have already been called,
    // before Init_Application, to construct main()'s global objects.
    int (* entry)();
    if(Traits<Build>::MODE == Traits<Build>::LIBRARY)
        entry = reinterpret_cast<int (*)()>(__epos_app_entry);
    else
        entry = reinterpret_cast<int (*)()>(System::info()->lm.app_entry);

    db<Init, Thread>(TRC) << "Thread::init(entry=" << reinterpret_cast<void *>(entry) << ")" << endl;

    // The installation of the scheduler timer handler must precede the
    // creation of threads, since the constructor can induce a reschedule
    // and this in turn can call timer->reset()
    // Letting reschedule() happen during thread creation is harmless, since
    // MAIN is created first and dispatch won't replace it nor by itself
    // neither by IDLE (that has a lower priority)
    if(Criterion::timed)
        _timer = new (SYSTEM) Scheduler_Timer(QUANTUM, time_slicer);

    // Create the application's main thread
    // This must precede idle, thus avoiding implicit rescheduling
    Thread * first;
    
    if(multitask) {
    	first = new (SYSTEM) Thread(*Task::_master, entry, RUNNING, MAIN);
    	new (SYSTEM) Thread(*Task::_master, &idle, READY, IDLE);
    } else {
    	first = new (SYSTEM) Thread(entry, RUNNING, MAIN);
    	new (SYSTEM) Thread(&idle, READY, IDLE);
    }

    db<Init, Thread>(INF) << "Dispatching the first thread: " << first << endl;

    This_Thread::not_booting();

    first->_context->load();
}

__END_SYS
