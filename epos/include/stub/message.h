#ifndef __message_h
#define __message_h

#include <system/config.h>

__BEGIN_API

class Message {

public:
	void class_id(int id);
	int class_id();

	void method_id(int id);
	int method_id();

	void object_id(void * id);
	void * object_id();

	void param1(void * ptr);
	void * param1();

	void param2(void * ptr);
	void * param2();

	void param3(void * ptr);
	void * param3();

	void param4(void * ptr);
	void * param4();

	void param5(void * ptr);
	void * param5();

	void param6(void * ptr);
	void * param6();

	void param7(void * ptr);
	void * param7();

	//void variadic1(void ...);
	//void * variadic1();
	
	//void variadic2(void ...);
	//void * variadic2();
	
	void return_value(void * ptr);
	void * return_value();

private:
	int _class_id;
	int _method_id;
	void * _object_id;
	void * _return;
	void * _param1;
	void * _param2;
	void * _param3;
	void * _param4;
	void * _param5;
	void * _param6;
	void * _param7;
	void * _variadic1[];
	void * _variadic2[];
	
};

__END_API
#endif
