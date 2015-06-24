// EPOS Thread Abstraction Declarations

#ifndef __thread_h
#define __thread_h

#include <utility/queue.h>
#include <utility/handler.h>
#include <cpu.h>
#include <mmu.h>
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

    // Thread Configuration
    struct Configuration {
        Configuration(const State & s = READY, const Criterion & c = NORMAL, unsigned int ss = STACK_SIZE)
        : state(s), criterion(c), stack_size(ss) {}

        State state;
        Criterion criterion;
        unsigned int stack_size;
    };

    // Thread Queue
    typedef Ordered_Queue<Thread, Criterion, Scheduler<Thread>::Element> Queue;


private:
    template<typename ... Cn, typename ... Tn>
    Thread(const Configuration & conf, Task * task, bool user_mode, int (* entry)(Tn ...), Tn ... an);


public:
    template<typename ... Tn>
    Thread(int (* entry)(Tn ...), Tn ... an);
    template<typename ... Tn>
    Thread(Task * task, int (* entry)(Tn ...), Tn ... an);
    template<typename ... Cn, typename ... Tn>
    Thread(const Configuration & conf, int (* entry)(Tn ...), Tn ... an);
    template<typename ... Cn, typename ... Tn>
    Thread(const Configuration & conf, Task * task, int (* entry)(Tn ...), Tn ... an);
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
    void constructor(const Log_Addr & entry, unsigned int stack_size);

    static Thread * volatile running() { return _scheduler.chosen(); }

    Queue::Element * link() { return &_link; }

    Criterion & criterion() { return const_cast<Criterion &>(_link.rank()); }

    static void lock() { CPU::int_disable(); }
    static void unlock() { CPU::int_enable(); }
    static bool locked() { return CPU::int_enabled(); }

    void suspend(bool locked);

    static void sleep(Queue * q);
    static void wakeup(Queue * q);
    static void wakeup_all(Queue * q);

    static void reschedule();
    static void time_slicer(const IC::Interrupt_Id & interrupt);

    static void implicit_exit();

    static void dispatch(Thread * prev, Thread * next, bool charge = true);

    static int idle();

private:
    static void init();

protected:
    Task * _task;
    Segment * _stack;
    Segment * _user_stack; // atributo novo
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

template<typename ... Tn>
inline Thread::Thread(int (* entry)(Tn ...), Tn ... an)
: _task(Task::self()), _state(READY), _waiting(0), _joining(0), _link(this, NORMAL)
{
    lock();

    _stack      = new (SYSTEM) Segment(STACK_SIZE, MMU::Flags(MMU::IA32_Flags::SYS));
    _user_stack = new (SYSTEM) Segment(STACK_SIZE);

    Address_Space * this_as = Task::self()->address_space();
    Log_Addr _sys_stack_addr = this_as->attach(*_stack);
    Log_Addr _user_stack_addr =this_as->attach(*_user_stack);

    char * user_stack_base = _user_stack_addr + STACK_SIZE;
    char * sys_stack_base  = _sys_stack_addr + STACK_SIZE;

    _context = CPU::init_stack(sys_stack_base, user_stack_base, true, &implicit_exit, entry, an ...);

    constructor(entry, STACK_SIZE); // implicit unlock
}

template<typename ... Tn>
inline Thread::Thread(Task * task, int (* entry)(Tn ...), Tn ... an)
: _task(task), _state(READY), _waiting(0), _joining(0), _link(this, NORMAL)
{
    lock();

    _stack      = new (SYSTEM) Segment(STACK_SIZE, MMU::Flags(MMU::IA32_Flags::SYS));
    _user_stack = new (SYSTEM) Segment(STACK_SIZE);

    Address_Space * this_as = Task::self()->address_space();
    this_as->attach(*_stack);
    this_as->attach(*_user_stack);

    Address_Space * as = task->address_space();
    Log_Addr _sys_stack_addr = as->attach(*_stack);
    Log_Addr _user_stack_addr = as->attach(*_user_stack);

    char * user_stack_base = _user_stack_addr + STACK_SIZE;
    char * sys_stack_base  = _sys_stack_addr + STACK_SIZE;

    _context = CPU::init_stack(sys_stack_base, user_stack_base, true, &implicit_exit, entry, an ...);

    this_as->detach(*_stack);
    this_as->detach(*_user_stack);

    constructor(entry, STACK_SIZE); // implicit unlock
}

template<typename ... Cn, typename ... Tn>
inline Thread::Thread(const Configuration & conf, int (* entry)(Tn ...), Tn ... an)
: _task(Task::self()), _state(conf.state), _waiting(0), _joining(0), _link(this, conf.criterion)
{
    lock();

    _stack      = new (SYSTEM) Segment(conf.stack_size, MMU::Flags(MMU::IA32_Flags::SYS));
    _user_stack = new (SYSTEM) Segment(STACK_SIZE);

    Address_Space * as = Task::self()->address_space();
    Log_Addr _sys_stack_addr  = as->attach(*_stack);
    Log_Addr _user_stack_addr = as->attach(*_user_stack);

    char * user_stack_base = _user_stack_addr + STACK_SIZE;
    char * sys_stack_base = _sys_stack_addr + conf.stack_size;

    _context = CPU::init_stack(sys_stack_base, user_stack_base, true, &implicit_exit, entry, an ...);
    constructor(entry, conf.stack_size); // implicit unlock
}

template<typename ... Cn, typename ... Tn>
inline Thread::Thread(const Configuration & conf, Task * task, int (* entry)(Tn ...), Tn ... an)
: _task(task), _state(conf.state), _waiting(0), _joining(0), _link(this, conf.criterion)
{
    lock();

    _stack      = new (SYSTEM) Segment(conf.stack_size, MMU::Flags(MMU::IA32_Flags::SYS));
    _user_stack = new (SYSTEM) Segment(STACK_SIZE);

    Address_Space * this_as = Task::self()->address_space();
    Log_Addr _sys_stack_addr = this_as->attach(*_stack);
    Log_Addr _user_stack_addr =this_as->attach(*_user_stack);

    Address_Space * as = _task->address_space();
    as->attach(*_stack);
    as->attach(*_user_stack);

    char * user_stack_base = _user_stack_addr + STACK_SIZE;
    char * sys_stack_base  = _sys_stack_addr + STACK_SIZE;

    _context = CPU::init_stack(sys_stack_base, user_stack_base, true, &implicit_exit, entry, an ...);

    this_as->detach(*_stack);
    this_as->detach(*_user_stack);

    constructor(entry, conf.stack_size); // implicit unlock
}

template<typename ... Cn, typename ... Tn>
inline Thread::Thread(const Configuration & conf, Task * task, bool user_mode, int (* entry)(Tn ...), Tn ... an)
: _task(task), _state(conf.state), _waiting(0), _joining(0), _link(this, conf.criterion)
{
    lock();

    _stack      = new (SYSTEM) Segment(conf.stack_size, MMU::Flags(MMU::IA32_Flags::SYS));
    _user_stack = new (SYSTEM) Segment(STACK_SIZE);

    Address_Space * this_as = Task::self()->address_space();
    this_as->attach(*_stack);
    this_as->attach(*_user_stack);

    Address_Space * as = _task->address_space();
    Log_Addr _sys_stack_addr = as->attach(*_stack);
    Log_Addr _user_stack_addr = as->attach(*_user_stack);

    char * user_stack_base = _user_stack_addr + STACK_SIZE;
    char * sys_stack_base  = _sys_stack_addr + STACK_SIZE;

    _context = CPU::init_stack(sys_stack_base, user_stack_base, user_mode, &implicit_exit, entry, an ...);

    this_as->detach(*_stack);
    this_as->detach(*_user_stack);

    constructor(entry, conf.stack_size); // implicit unlock
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
