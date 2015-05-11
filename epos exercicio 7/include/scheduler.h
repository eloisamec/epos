#ifndef __scheduler_h
#define __scheduler_h

#include <utility/list.h>
#include <cpu.h>
#include <machine.h>

__BEGIN_SYS

namespace Scheduling_Criteria
{
    class Priority
    {
    public:
        enum {
            MAIN   = 0,
            HIGH   = 1,
            NORMAL = (unsigned(1) << (sizeof(int) * 8 - 1)) - 3,
            LOW    = (unsigned(1) << (sizeof(int) * 8 - 1)) - 2,
            IDLE   = (unsigned(1) << (sizeof(int) * 8 - 1)) - 1
        };

        static const bool timed = false;
        static const bool preemptive = true;

    public:
        Priority(int p = NORMAL): _priority(p) {}

        operator const volatile int() const volatile { return _priority; }

    protected:
        volatile int _priority;
    };

    class RR: public Priority
    {
    public:
        enum {
            MAIN   = 0,
            NORMAL = 1,
            IDLE   = (unsigned(1) << (sizeof(int) * 8 - 1)) - 1
        };

        static const bool timed = true;
        static const bool preemptive = true;

    public:
        RR(int p = NORMAL): Priority(p) {}
    };

    class FCFS: public Priority
    {
    public:
        enum {
            MAIN   = 0,
            NORMAL = 1,
            IDLE   = (unsigned(1) << (sizeof(int) * 8 - 1)) - 1
        };

        static const bool timed = false;
        static const bool preemptive = false;

    public:
        FCFS(int p = NORMAL): Priority((p == IDLE) ? IDLE : TSC::time_stamp()) {}
    };
}


template <typename T, typename R = typename T::Criterion>
class Scheduling_Queue: public Scheduling_List<T> {};

template <typename T>
class Scheduler: public Scheduling_Queue<T>
{
private:
    typedef Scheduling_Queue<T> Base;

public:
    typedef typename T::Criterion Criterion;
    typedef Scheduling_List<T, Criterion> Queue;
    typedef typename Queue::Element Element;

public:
    Scheduler() {}

    unsigned int schedulables() { return Base::size(); }

    T * volatile chosen() { 
    	return const_cast<T * volatile>(Base::chosen()->object());
    }

    void insert(T * obj) {
        Base::insert(obj->link());
    }

    T * remove(T * obj) {
        return Base::remove(obj->link()) ? obj : 0;
    }

    void suspend(T * obj) {
        Base::remove(obj->link());
    }

    void resume(T * obj) {
        Base::insert(obj->link());
    }

    T * choose() {
        T * obj = Base::choose()->object();
        return obj;
    }

    T * choose_another() {
        T * obj = Base::choose_another()->object();
        return obj;
    }

    T * choose(T * obj) {
        if(!Base::choose(obj->link()))
            obj = 0;
        return obj;
    }
};

__END_SYS

#endif