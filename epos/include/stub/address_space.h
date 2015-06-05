#ifndef ADDRESS_SPACE_H
#define ADDRESS_SPACE_H

#include <table_class_method.h>
#include <stub/message.h>
#include <stub/skeleton.h>
#include <architecture/ia32/mmu.h>
#include <system/config.h>


__BEGIN_API

class Address_Space {

public:
    Address_Space() {
        message = new Message();
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::CONSTRUCTOR);
        Skeleton::call(message);
        _obj_id = message->return_value();
    };

    Address_Space(MMU::Page_Directory * pd) {
        message = new Message();
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::CONSTRUCTOR);
        message->param1(pd);
        Skeleton::call(message);
        _obj_id = message->return_value();
    };

    ~Address_Space(){
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::DESTRUCTOR);
        message->object_id(_obj_id);
        Skeleton::call(message);
        delete message;
    };

    void attach1(const Segment & seg){
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::ATTACH_1);
        message->object_id(_obj_id);
        Skeleton::call(message);
    };

    void attach2(const Segment & seg, API::Log_Addr addr){
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::ATTACH_2);
        message->object_id(_obj_id);
        Skeleton::call(message);
    };

    void detach(){
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::DETACH);
        message->object_id(_obj_id);
        Skeleton::call(message);
    };

    void physical(const Segment & seg, API::Log_Addr addr){
        message->class_id(Class::ADDRESS_SPACE);
        message->method_id(Method::Address_Space::ATTACH_2);
        message->object_id(_obj_id);
        Skeleton::call(message);
    };

private:
   void * _obj_id;
   Message * message;
};

__END_API
#endif
