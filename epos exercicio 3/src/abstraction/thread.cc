// EPOS Thread Abstraction Implementation

#include <system/kmalloc.h>
#include <machine.h>
#include <thread.h>
#include <alarm.h>

// This_Thread class attributes
__BEGIN_UTIL
bool This_Thread::_not_booting;
__END_UTIL

__BEGIN_SYS

// Class attributes
Scheduler_Timer * Thread::_timer;

Thread* volatile Thread::_running;
Thread::Queue Thread::_ready;
Thread::Queue Thread::_suspended;

// Methods
void Thread::constructor(const Log_Addr & entry, unsigned int stack_size)
{
    db<Thread>(TRC) << "Thread(entry=" << entry
                    << ",state=" << _state
                    << ",priority=" << _link.rank()
                    << ",stack={b=" << _stack
                    << ",s=" << stack_size
                    << "},context={b=" << _context
                    << "," << *_context << "}) => " << this << endl;

    switch(_state) {
        case RUNNING: break;
        case SUSPENDED: _suspended.insert(&_link); break;
        default: _ready.insert(&_link);
    }
	
	if(preemptive && (_state == READY) && (_link.rank() != IDLE))
		reschedule();
	else
		unlock();
}


Thread::~Thread()
{
    lock();

    db<Thread>(TRC) << "~Thread(this=" << this
            << ",state=" << _state
            << ",stack={b=" << _stack
            << ",context={b=" << _context
            << "," << *_context << "})\n";

	_ready.remove(this);
    _suspended.remove(this);
	
    if(_waiting)
        _waiting->remove(this);

    if(_joining)
        _joining->resume();

    unlock();

    kfree(_stack);
}


int Thread::join()
{
    lock();

    db<Thread>(TRC) << "Thread::join(this=" << this << ",state=" << _state << ")" << endl;

    // Precondition: no Thread::self()->join()
    assert(running() != this);

     // Precondition: a single joiner
     assert(!_joining);

     if(_state != FINISHING) {
         _joining = running();
         _joining->suspend();
     } else
         unlock();

    return *reinterpret_cast<int *>(_stack);
}


void Thread::pass()
{
    lock();

    db<Thread>(TRC) << "Thread::pass(this=" << this << ")" << endl;

    Thread * prev = _running;
    prev->_state = READY;
    _ready.insert(&prev->_link);

    _ready.remove(this);
    _state = RUNNING;
    _running = this;

    dispatch(prev, this);

    unlock();
}


void Thread::suspend()
{
    lock();

    db<Thread>(TRC) << "Thread::suspend(this=" << this << ")" << endl;

    if(_running != this)
        _ready.remove(this);

    _state = SUSPENDED;
    _suspended.insert(&_link);

    if(_running == this) {
       // while(_ready.empty())
       //     idle();

        _running = _ready.remove()->object();
        _running->_state = RUNNING;

        dispatch(this, _running);
    }

    unlock();
}


void Thread::resume()
{
    lock();

    db<Thread>(TRC) << "Thread::resume(this=" << this << ")" << endl;

   _suspended.remove(this);
   _state = READY;
   _ready.insert(&_link);

   unlock();
}


// Class methods
void Thread::yield()
{
    lock();

    db<Thread>(TRC) << "Thread::yield(running=" << _running << ")" << endl;

    //if(!_ready.empty()) {
        Thread * prev = _running;
        prev->_state = READY;
        _ready.insert(&prev->_link);

        _running = _ready.remove()->object();
        _running->_state = RUNNING;

        dispatch(prev, _running);
    //} else
    //    idle();

    unlock();
}


void Thread::exit(int status)
{
    lock();

    db<Thread>(TRC) << "Thread::ext(running=" << running() << ")" << endl;

    Thread * prev = _running;
    prev->_state = FINISHING;
    *reinterpret_cast<int *>(prev->_stack) = status;

	if(prev->_joining) {
        prev->_joining->resume();
        prev->_joining = 0;
    }
	
    lock();

    //if(_ready.empty()) {
    //    if(!_suspended.empty()) {
    //        while(_ready.empty())
    //            idle(); // implicit unlock();
    //        lock();
    //    } else { // _ready.empty() && _suspended.empty()
    //        db<Thread>(WRN) << "The last thread in the system has exited!\n";
    //        if(reboot) {
    //            db<Thread>(WRN) << "Rebooting the machine ...\n";
    //            Machine::reboot();
    //        } else {
    //            db<Thread>(WRN) << "Halting the CPU ...\n";
    //            CPU::halt();
    //        }
    //    }
    //} else {
        _running = _ready.remove()->object();
        _running->_state = RUNNING;

        dispatch(prev, _running);
    //}

    unlock();
}

void Thread::sleep(Queue * q)
{
    db<Thread>(TRC) << "Thread::sleep(running=" << running() << ",q=" << q << ")" << endl;

    // lock() must be called before entering this method
    assert(locked());

    //while(_ready.empty())
    //    idle();

    Thread * prev = running();
    prev->_state = WAITING;
    prev->_waiting = q;
    q->insert(&prev->_link);

    _running = _ready.remove()->object();
    _running->_state = RUNNING;

    dispatch(prev, _running);

    unlock();
}


void Thread::wakeup(Queue * q)
{
    db<Thread>(TRC) << "Thread::wakeup(running=" << running() << ",q=" << q << ")" << endl;

    // lock() must be called before entering this method
    assert(locked());

    if(!q->empty()) {
        Thread * t = q->remove()->object();
        t->_state = READY;
        t->_waiting = 0;
        _ready.insert(&t->_link);
    }

    unlock();

    if(preemptive)
        reschedule();
}


void Thread::wakeup_all(Queue * q)
{
    db<Thread>(TRC) << "Thread::wakeup_all(running=" << running() << ",q=" << q << ")\n";

    // lock() must be called before entering this method
    assert(locked());

    while(!q->empty()) {
        Thread * t = q->remove()->object();
        t->_state = READY;
        t->_waiting = 0;
        _ready.insert(&t->_link);
    }

    unlock();

    if(preemptive)
        reschedule();
}


void Thread::reschedule()
{
    yield();
}


void Thread::time_slicer(const IC::Interrupt_Id & interrupt)
{
    reschedule();
}


void Thread::implicit_exit()
{
    exit(CPU::fr());
}


int Thread::idle()
{
	while(true) {
		db<Thread>(TRC) << "Thread::idle()" << endl;
		CPU::int_disable();
		
		if(!_suspended.empty()) {
			db<Thread>(INF) << "There are no runnable threads at the moment!" << endl;
			CPU::int_enable();
			db<Thread>(INF) << "Halting the CPU ..." << endl;
			CPU::halt();
		} else {
			db<Thread>(WRN) << "The last thread in the system has exited!\n";
			if(reboot) {
                db<Thread>(WRN) << "Rebooting the machine ...\n";
                Machine::reboot();
            } else {
                db<Thread>(WRN) << "Halting the CPU ...\n";
                CPU::halt();
				if (_ready.size() > 1) {
					yield();
				}
            }
		}
	}
    
	return 0;
}

__END_SYS

// Id forwarder to the spin lock
__BEGIN_UTIL
unsigned int This_Thread::id()
{
    return _not_booting ? reinterpret_cast<volatile unsigned int>(Thread::self()) : Machine::cpu_id() + 1;
}
__END_UTIL
