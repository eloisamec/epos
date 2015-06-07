#include <stub/message.h>

__BEGIN_API

	void Message::class_id(int id) { _class_id = id; }
	int Message::class_id() { return _class_id; }

	void Message::method_id(int id) { _method_id = id; }
	int Message::method_id() { return _method_id; }

	void Message::object_id(void * id){ _object_id = id; }
	void * Message::object_id(){ return _object_id; }

	void Message::param1(void * ptr) { _param1 = ptr; }
	void * Message::param1() { return _param1; }

	void Message::param2(void * ptr) { _param2 = ptr; }
	void * Message::param2() { return _param2; }

	void Message::param3(void * ptr){ _param3 = ptr; }
	void * Message::param3(){ return _param3; }

	void Message::param4(void * ptr){ _param4 = ptr; }
	void * Message::param4(){ return _param4; }

	void Message::param5(void * ptr){ _param5 = ptr; }
	void * Message::param5(){ return _param5; }

	void Message::param6(void * ptr){ _param6 = ptr; }
	void * Message::param6(){ return _param6; }

	void Message::param7(void * ptr){ _param7 = ptr; }
	void * Message::param7(){ return _param7; }

	//void variadic1(void...) { 
	//	int size = sizeof...(void ...);
	//	_variadic1[size] = {void ...};
	//}
	//void * variadic1[]() { return _variadic1[]; }
	
	//void variadic2[](void ... *ptr) { 
	//	int size = sizeof...(ptr);
	//	_variadic2[size] = {ptr...};
	//}
	//void * variadic2[]() { return _variadic2[]; }
	
	void Message::return_value(void * ptr){ _return = ptr; }
	void * Message::return_value(){ return _return; }

__END_API