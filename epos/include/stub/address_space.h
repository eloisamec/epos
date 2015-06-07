#ifndef __address_space_h
#define __address_space_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Address_Space {

public:

    Address_Space() {
		message = new Message();
    	message->class_id(Class::ADDRESS_SPACE);
    	message->method_id(Method::Address_Space::CONSTRUCTOR_1);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    };
	
	Address_Space(MMU::Page_Directory * pd) {
		message = new Message();
    	message->class_id(Class::ADDRESS_SPACE);
    	message->method_id(Method::Address_Space::CONSTRUCTOR_2);
		message->param1((void*) &pd);
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

    Log_Addr attach(const Segment & seg) {
    	message->class_id(Class::ADDRESS_SPACE);
    	message->method_id(Method::Address_Space::ATTACH_1);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Log_Addr address = reinterpret_cast<Log_Addr> message->return_value();
		return address;
    };

	Log_Addr attach(const Segment & seg, Address_Space::Log_Addr addr) {
    	message->class_id(Class::ADDRESS_SPACE);
    	message->method_id(Method::Address_Space::ATTACH_2;
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Address_Space * address_space = reinterpret_cast<Address_Space *> message->return_value();
		return address_space;
    };
	
    void detach(const Segment & seg){
    	message->class_id(Class::ADDRESS_SPACE);
    	message->method_id(Method::Address_Space::DETACH);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
    };
	
	Phy_Addr physical(Address_Space::Log_Addr address) {
    	message->class_id(Class::ADDRESS_SPACE);
    	message->method_id(Method::Address_Space::PHYSICAL);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Address_Space * address_space = reinterpret_cast<Address_Space *> message->return_value();
		return address_space;
    };

private:
   void * _obj_id;
   Message * message;
};

__END_APP
#endif