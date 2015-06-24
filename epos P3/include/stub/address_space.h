#ifndef __stub_address_space_h
#define __stub_address_space_h

#include <api_types.h>
#include <stub/stub.h>
#include <stub/segment.h>

__BEGIN_APPLICATION

class Address_Space :  Stub
{
    friend class Task;

private:
    Address_Space(int object_id): _object_id(object_id) {}

public:
    Address_Space(){
        int * message = new int[4] {Class::ADDRESS_SPACE, Method::Address_Space::CONSTRUCTOR_1, 0, 0};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    Address_Space(Page_Directory * pd ){
        int ipd = reinterpret_cast<int>(&pd);
        int * message = new int[5] {Class::ADDRESS_SPACE, Method::Address_Space::CONSTRUCTOR_1, 0, 0, ipd};
        syscall(message);
        _object_id = message[2];
        delete message;
    }

    ~Address_Space(){
        int * message = new int[4] {Class::ADDRESS_SPACE, Method::Address_Space::DESTRUCTOR, _object_id, 0};
        syscall(message);
        delete message;
    }

    Log_Addr attach(Segment &segment ){
        int isegment = segment._object_id;
        int * message = new int[5] {Class::ADDRESS_SPACE, Method::Address_Space::ATTACH_1, _object_id, 0, isegment};
        syscall(message);
        Log_Addr log_addr = *reinterpret_cast<Log_Addr*>(message[3]);
        delete message;
        return log_addr;
    }

    Log_Addr attach(const Segment & seg, Log_Addr addr ){
        int isegment = seg._object_id;
        int * iaddr = reinterpret_cast<int*>(&addr);
        int * message = new int[5] {Class::ADDRESS_SPACE, Method::Address_Space::ATTACH_2, _object_id, isegment, *iaddr};
        syscall(message);
        Log_Addr log_addr = *reinterpret_cast<Log_Addr*>(message[3]);
        delete message;
        return log_addr;
    }

    void detach( const Segment & seg ){
        int isegment = seg._object_id;
        int * message = new int[5] {Class::ADDRESS_SPACE, Method::Address_Space::DETACH, _object_id, 0, isegment};
        syscall(message);
        delete message;
    }

    Phy_Addr physical(const Log_Addr addr){
        Log_Addr * log_addr = static_cast<Log_Addr*>(addr);
        int * iaddr = reinterpret_cast<int*>(log_addr);
        int * message = new int[5] {Class::ADDRESS_SPACE, Method::Address_Space::PHYSICAL, _object_id, *iaddr};
        syscall(message);
        Phy_Addr result = *reinterpret_cast<Phy_Addr*>(message[3]);
        delete message;
        return result;
    }

    Phy_Addr pd() {
        int * message = new int[4] {Class::ADDRESS_SPACE, Method::Address_Space::PD, _object_id, 0};
        syscall(message);
        Phy_Addr result = *reinterpret_cast<Phy_Addr*>(message[3]);
        delete message;
        return result;
    }

private:
  int _object_id;

};

__END_APPLICATION

#endif
