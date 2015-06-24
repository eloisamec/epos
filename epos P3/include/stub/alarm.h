#ifndef __stub_ALARM_h
#define __stub_ALARM_h

#include <api_types.h>
#include <stub/stub.h>

__BEGIN_APPLICATION

class Alarm : Stub
{

public:
    Alarm(const Microsecond & time, Function * handler, int times = 1){
        int itime = reinterpret_cast<int>(&time);
        int ihandler = reinterpret_cast<int>(handler);
        int * message = new int[7] {Class::ALARM, Method::Alarm::CONSTRUCTOR, 0, 0, itime, ihandler, times};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Alarm(){
        int * message = new int[4] {Class::ALARM, Method::Alarm::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    static Hertz frequency(){
        int * message = new int[4] {Class::ALARM, Method::Alarm::FREQUENCY, 0, 0};
        syscall(message);
        Hertz frequency = *reinterpret_cast<Hertz*>(message[3]);
    }

    static void delay(const Microsecond & time){
        int itime = reinterpret_cast<int>(&time);
        int * message = new int[5] {Class::ALARM, Method::Alarm::DELAY, 0, 0, itime};
        syscall(message);
        delete message;
    }

private:
    int _object_id;
};



class Delay : Stub
{

public:
    Delay(const Microsecond & time){
        int itime = reinterpret_cast<int>(&time);
        int * message = new int[5]{Class::DELAY, Method::Delay::CONSTRUCTOR, 0, 0, itime};
        syscall(message);
    }
};

__END_APPLICATION

#endif
