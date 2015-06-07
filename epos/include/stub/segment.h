#ifndef __segment_h
#define __segment_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Segment {

public:
	Segment(unsigned int bytes, Flags flags = Flags::APP) {
		message = new Message();
    	message->class_id(Class::SEGMENT);
    	message->method_id(Method::Segment::CONSTRUCTOR_1);
    	message->param1((void*) &bytes);
    	message->param1((void*) &flags);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    };
	
	Segment(Phy_Addr phy_addr, unsigned int bytes, Flags flags = Flags::APP) {
		message = new Message();
    	message->class_id(Class::SEGMENT);
    	message->method_id(Method::Segment::CONSTRUCTOR_2);
    	message->param1((void*) &phy_addr);
    	message->param1((void*) &bytes);
    	message->param1((void*) &flags);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
    };
	
    ~Segment(){
    	message->class_id(Class::SEGMENT);
    	message->method_id(Method::Segment::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
    };

	unsigned int size() const{
    	message->class_id(Class::SEGMENT);
    	message->method_id(Method::Segment::SIZE);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		unsigned int size = reinterpret_cast<int*>(message->return_value());
		return size;
    };

    Phy_Addr phy_address() const{
    	message->class_id(Class::SEGMENT);
    	message->method_id(Method::Segment::PHY_ADDRESS);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Phy_Addr phy_addr = reinterpret_cast<Phy_Addr*>(message->return_value());
		return phy_addr;
    };
	
	int resize(int amount){
    	message->class_id(Class::SEGMENT);
    	message->method_id(Method::Segment::PHY_ADDRESS);
    	message->object_id(_obj_id);
		message->param1(&amount);
    	Skeleton::call(message);
		int size = reinterpret_cast<int*>(message->return_value());
		return size;
    };

private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif
