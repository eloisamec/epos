// EPOS Thread Abstraction Declarations

#ifndef __thread_h
#define __thread_h

#include <utility/queue.h>
#include <utility/handler.h>
#include <cpu.h>
#include <machine.h>
#include <system.h>
#include <scheduler.h>

__BEGIN_SYS

class Thread
{
    friend class Init_First;
    friend class Scheduler<Thread>;
    friend class Synchronizer_Common;
    friend class Alarm;
    friend class Task;
    friend class IA32;

protected:
    static const bool preemptive = Traits<Thread>::Criterion::preemptive;
    static const bool multitask = Traits<System>::multitask;

    static const bool reboot = Traits<System>::reboot;

    static const unsigned int QUANTUM = Traits<Thread>::QUANTUM;
    static const unsigned int STACK_SIZE = Traits<Application>::STACK_SIZE;

    typedef CPU::Log_Addr Log_Addr;
    typedef CPU::Context Context;

public:
    // Thread State
    enum State {
        RUNNING,
        READY,
        SUSPENDED,
        WAITING,
        FINISHING
    };

    // Thread Priority
    typedef Scheduling_Criteria::Priority Priority;

    // Thread Scheduling Criterion
    typedef Traits<Thread>::Criterion Criterion;
    enum {
        HIGH    = Criterion::HIGH,
        NORMAL  = Criterion::NORMAL,
        LOW     = Criterion::LOW,
        MAIN    = Criterion::MAIN,
        IDLE    = Criterion::IDLE
    };

    // Thread Queue
    typedef Ordered_Queue<Thread, Criterion, Scheduler<Thread>::Element> Queue;

public:
    Thread(int (* entry)(),
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1>
    Thread(int (* entry)(T1 a1), T1 a1,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1, typename T2>
    Thread(int (* entry)(T1 a1, T2 a2), T1 a1, T2 a2,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1, typename T2, typename T3>
    Thread(int (* entry)(T1 a1, T2 a2, T3 a3), T1 a1, T2 a2, T3 a3,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1, typename T2, typename T3, typename T4>
    Thread(int (* entry)(T1 a1, T2 a2, T3 a3, T4 a4), T1 a1, T2 a2, T3 a3, T4 a4,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);

    Thread(const Task & task, int (* entry)(),
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1>
    Thread(const Task & task, int (* entry)(T1 a1), T1 a1,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1, typename T2>
    Thread(const Task & task, int (* entry)(T1 a1, T2 a2), T1 a1, T2 a2,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1, typename T2, typename T3>
    Thread(const Task & task, int (* entry)(T1 a1, T2 a2, T3 a3), T1 a1, T2 a2, T3 a3,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);
    template<typename T1, typename T2, typename T3, typename T4>
    Thread(const Task & task, int (* entry)(T1 a1, T2 a2, T3 a3, T4 a4), T1 a1, T2 a2, T3 a3, T4 a4,
           const State & state = READY, const Criterion & criterion = NORMAL, unsigned int stack_size  = STACK_SIZE, char * user_stack = 0);

    ~Thread();

    const volatile State & state() const { return _state; }

    const volatile Priority & priority() const { return _link.rank(); }
    void priority(const Priority & p);

    Task * task() const { return const_cast<Task *>(_task); }

    int join();
    void pass();
    void suspend() { suspend(false); }
    void resume();

    static Thread * volatile self() { return running(); }
    static void yield();
    static void exit(int status = 0);

protected:
    void common_constructor(Log_Addr entry, unsigned int stack_size);

    static Thread * volatile running() { return _scheduler.chosen(); }

    Queue::Element * link() { return &_link; }

    Criterion & criterion() { return const_cast<Criterion &>(_link.rank()); }

    static void lock() { CPU::int_disable(); }
    static void unlock() { CPU::int_enable(); }
    static bool locked() { return CPU::int_disabled(); }

    void suspend(bool locked);

    static void sleep(Queue * q);
    static void wakeup(Queue * q);
    static void wakeup_all(Queue * q);

    static void reschedule();
    static void time_slicer();

    static void implicit_exit();

    static void dispatch(Thread * prev, Thread * next, bool charge = true);

    static int idle();

private:
    static void init();

protected:
    const Task * _task;
    char * _stack;
    char * _user_stack;
    Context * volatile _context;
    volatile State _state;
    Queue * _waiting;
    Thread * volatile _joining;
    Queue::Element _link;

    static volatile unsigned int _thread_count;
    static Scheduler_Timer * _timer;
    static Scheduler<Thread> _scheduler;
};

__END_SYS

#include <task.h>

__BEGIN_SYS

inline Thread::Thread(int (* entry)(), const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(Task::self()), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock
}

template<typename T1>
inline Thread::Thread(int (* entry)(T1 a1), T1 a1, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(Task::self()), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

template<typename T1, typename T2>
inline Thread::Thread(int (* entry)(T1 a1, T2 a2), T1 a1, T2 a2, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(Task::self()), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1, a2);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

template<typename T1, typename T2, typename T3>
inline Thread::Thread(int (* entry)(T1 a1, T2 a2, T3 a3), T1 a1, T2 a2, T3 a3, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(Task::self()), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1, a2, a3);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

template<typename T1, typename T2, typename T3, typename T4>
inline Thread::Thread(int (* entry)(T1 a1, T2 a2, T3 a3, T4 a4), T1 a1, T2 a2, T3 a3, T4 a4, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(Task::self()), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1, a2, a3, a4);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

inline Thread::Thread(const Task & task, int (* entry)(), const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(&task), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock
}

template<typename T1>
inline Thread::Thread(const Task & task, int (* entry)(T1 a1), T1 a1, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(&task), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

template<typename T1, typename T2>
inline Thread::Thread(const Task & task, int (* entry)(T1 a1, T2 a2), T1 a1, T2 a2, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(&task), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1, a2);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

template<typename T1, typename T2, typename T3>
inline Thread::Thread(const Task & task, int (* entry)(T1 a1, T2 a2, T3 a3), T1 a1, T2 a2, T3 a3, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(&task), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1, a2, a3);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

template<typename T1, typename T2, typename T3, typename T4>
inline Thread::Thread(const Task & task, int (* entry)(T1 a1, T2 a2, T3 a3, T4 a4), T1 a1, T2 a2, T3 a3, T4 a4, const State & state, const Criterion & criterion, unsigned int stack_size, char * user_stack)
: _task(&task), _state(state), _waiting(0), _joining(0), _link(this, criterion)
{
    lock();

    _user_stack = user_stack;
    _stack = new (SYSTEM) char[stack_size];
    _context = CPU::init_stack(_stack, stack_size, &implicit_exit, entry, a1, a2, a3, a4);
    _context->usp(user_stack + stack_size);

    common_constructor(entry, stack_size); // implicit unlock()
}

// An event handler that triggers a thread (see handler.h)
class Thread_Handler : public Handler
{
public:
    Thread_Handler(Thread * h) : _handler(h) {}
    ~Thread_Handler() {}

    void operator()() { _handler->resume(); }

private:
    Thread * _handler;
};

__END_SYS

#endif
