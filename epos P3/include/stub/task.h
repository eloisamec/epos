#ifndef __stub_task_h
#define __stub_task_h

#include <api_types.h>
#include <stub/stub.h>
#include <stub/segment.h>
#include <stub/address_space.h>
#include <stub/thread.h>

__BEGIN_APPLICATION

class Task : Stub
{
    friend class Thread;
private:
    Task(int object_id ) : _object_id(object_id) { }

public:

    Task(Segment & cs, Segment & ds){
        int cs_address = cs._object_id;
        int ds_address = ds._object_id;
        int * message = new int[6] {Class::TASK, Method::Task::CONSTRUCTOR, 0, 0, cs_address, ds_address};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Task(){
        int * message = new int[4] {Class::TASK, Method::Task::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    Address_Space * address_space(){
        int * message = new int[4] {Class::TASK, Method::Task::ADDRESS_SPACE, _object_id, 0};
        syscall(message);
        Address_Space * as = new Address_Space(message[3]);
        delete message;
        return as;
    }

    Segment * code_segment(){
        int * message = new int[4] {Class::TASK, Method::Task::CODE_SEGMENT, _object_id, 0};
        syscall(message);
        Segment * seg = new Segment(message[3]);
        delete message;
        return seg;
    }

    Log_Addr code(){
        int * message = new int[4] {Class::TASK, Method::Task::CODE, _object_id, 0};
        syscall(message);
        Log_Addr la_code = *reinterpret_cast<Log_Addr*>(message[3]);
        delete message;
        return la_code;
    }

    Segment * data_segment(){
        int * message = new int[4] {Class::TASK, Method::Task::CODE_SEGMENT, _object_id, 0};
        syscall(message);
        Segment * seg = new Segment(message[3]);
        delete message;
        return seg;
    }
    Log_Addr data(){
        int * message = new int[4] {Class::TASK, Method::Task::CODE, _object_id, 0};
        syscall(message);
        Log_Addr la_data = *reinterpret_cast<Log_Addr*>(message[3]);
        delete message;
        return la_data;
    }
    static Task * self(){
        int * message = new int[4] {Class::TASK, Method::Task::SELF, 0, 0};
        syscall(message);
        delete message;
        return new Task(message[3]);
    }

private:
    int _object_id;
};

__END_APPLICATION

#endif
