// EPOS Component Framework - Component Agent

#ifndef __agent_h
#define __agent_h

#include "stub.h"
#include "message.h"

__BEGIN_SYS

template<typename Component>
class Agent
{
public:
    static void act(Message * msg) {
        msg->reply(Result(-1));
    }
};


#include <alarm.h>
template <>
class Agent<Alarm>
{
public:
    static void act(Message * msg) {
        db<Alarm>(TRC) << "Alarm Agent::act>>" << endl;

        Result res = 0;

        switch(msg->method()) {
        case Method::DESTROY: {
            db<Alarm>(TRC) << "Alarm Agent::DESTROY" << endl;
            Adapter<Alarm> * alarm = reinterpret_cast<Adapter<Alarm> *>(msg->id().unit());
            delete alarm;
        }
        break;
        case Method::CREATE3: {
            db<Alarm>(TRC) << "Alarm Agent::CREATE3" << endl;
            Alarm::Microsecond time;
            Handler* handler;
            int times;
            msg->in(time, handler, times);
            msg->id(new Adapter<Alarm>(time, handler, times));
        }
        break;
        case Method::ALARM_DELAY: {
            db<Alarm>(TRC) << "Alarm Agent::ALARM_DELAY" << endl;
            Alarm::Microsecond time;
            msg->in(time);
            Adapter<Alarm>::delay(time);
        }
        break;
        default:
            db<Alarm>(WRN) << "Alarm Agent: unknown method: " << msg->method() << endl;
        break;
        }

        msg->reply(res);

        db<Alarm>(TRC) << "<<Alarm Agent::act" << endl;
    }
};


#include <thread.h>
template <>
class Agent<Thread>
{
public:
    static void act(Message * msg) {
        Adapter<Thread> * thread = reinterpret_cast<Adapter<Thread> *>(msg->id().unit());
        Result res = 0;

        switch(msg->method()) {
        case Method::CREATE1: {
            int (*entry)();
            msg->in(entry);
            msg->id(new Adapter<Thread>(entry));
        }
        break;
        case Method::CREATE2: {
            Adapter<Task> * task;
            int (*entry)();
            msg->in(task, entry);
            msg->id(new Adapter<Thread>(*task, entry));
        }
        break;
        case Method::DESTROY:
            delete thread;
            break;
        case Method::SELF:
            msg->id(Adapter<Thread>::self());
            break;
        case Method::THREAD_SUSPEND:
            thread->suspend();
            break;
        case Method::THREAD_RESUME:
            thread->resume();
            break;
        case Method::THREAD_JOIN:
            res = thread->join();
            break;
        case Method::THREAD_PASS:
            thread->pass();
            break;
        case Method::THREAD_YIELD:
            Thread::yield();
            break;
        case Method::THREAD_EXIT: {
            int r;
            msg->in(r);
            Thread::exit();
        }
        break;
        }

        msg->reply(res);
    }
};

#include <task.h>
template<>
class Agent<Task>
{
public:
    static void act(Message * msg) {
        Adapter<Task> * task = reinterpret_cast<Adapter<Task> *>(msg->id().unit());
        Result res = 0;

        switch(msg->method()) {
        case Method::CREATE2: {
            Segment * cs, * ds;
            msg->in(cs, ds);
            msg->id(new Adapter<Task>(*cs, *ds));
        }
        break;
        case Method::DESTROY:
            delete task;
            break;
        case Method::SELF:
            msg->id(Adapter<Task>::self());
            break;
        case Method::TASK_ADDRESS_SPACE:
            res = task->address_space();
            break;
        case Method::TASK_CODE_SEGMENT:
            res = task->code_segment();
            break;
        case Method::TASK_DATA_SEGMENT:
            res = task->data_segment();
            break;
        case Method::TASK_CODE:
            res = task->code();
            break;
        case Method::TASK_DATA:
            res = task->data();
            break;
        }

        msg->reply(res);
    }
};

#include <address_space.h>
template<>
class Agent<Address_Space>
{
public:
    static void act(Message * msg) {
        Adapter<Address_Space> * as = reinterpret_cast<Adapter<Address_Space> *>(msg->id().unit());
        Result res = 0;

        switch(msg->method()) {
        case Method::CREATE:
            msg->id(new Adapter<Address_Space>());
            break;
        case Method::DESTROY:
            delete as;
            break;
        case Method::ADDRESS_SPACE_ATTACH1: {
            Segment * seg;
            msg->in(seg);
            res = as->attach(*seg);
        }
        break;
        case Method::ADDRESS_SPACE_ATTACH2: {
            Segment * seg;
            CPU::Log_Addr addr;
            msg->in(seg, addr);
            res = as->attach(*seg, addr);
        }
        break;
        case Method::ADDRESS_SPACE_DETACH: {
            Segment * seg;
            msg->in(seg);
            as->detach(*seg);
        }
        break;
        case Method::ADDRESS_PHYSICAL: {
            CPU::Log_Addr addr;
            msg->in(addr);
            res = as->physical(addr);
        }
        break;
        }

        msg->reply(res);
    }
};


#include <segment.h>
template<>
class Agent<Segment>
{
public:
    static void act(Message * msg) {
        Adapter<Segment> * seg = reinterpret_cast<Adapter<Segment> *>(msg->id().unit());
        Result res = 0;

        switch(msg->method()) {
        case Method::CREATE1: {
            unsigned int bytes;
            msg->in(bytes);
            msg->id(new Adapter<Segment>(bytes));
        }
        break;
        case Method::CREATE2: { // *** indistinguishable ***
            unsigned int bytes;
            Segment::Flags flags;
            msg->in(bytes, flags);
            msg->id(new Adapter<Segment>(bytes, flags));
        }
        break;
        case Method::CREATE3: { // *** indistinguishable ***
            Segment::Phy_Addr phy_addr;
            unsigned int bytes;
            Segment::Flags flags;
            msg->in(phy_addr, bytes, flags);
            msg->id(new Adapter<Segment>(phy_addr, bytes, flags));
        }
        break;
        case Method::DESTROY:
            delete seg;
            break;
        case Method::SEGMENT_SIZE:
            res = seg->size();
            break;
        case Method::SEGMENT_PHY_ADDRESS:
            res = seg->phy_address();
            break;
        case Method::SEGMENT_RESIZE: {
            int amount;
            msg->in(amount);
            res = seg->resize(amount);
        }
        break;
        }

        msg->reply(res);
    }
};

template<>
class Agent<Utility>
{
public:
    static void act(Message * msg) {
        Result res = 0;

        switch(msg->method()) {
        case Method::PRINT: {
            const char * s;
            msg->in(s);
            _print(s);
        }
        }

        msg->reply(res);
    }
};

__END_SYS

#endif
