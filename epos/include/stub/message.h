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

	template<typename ... Tn>
	void variadic1(Tn &... args) { 
		variadics(&_params1[0], args...);
	}
	
	void * variadic1() { return &_params1[20]; }
	
	template<typename ... Tn>
	void variadic2(Tn &... args) {
		variadics(&_params2[0], args...);
	}

	void * variadic2() { return &_params2[20]; }
	
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
	char _params1[20];
	char _params2[20];
	
	template< typename Head, typename ... Tail >
    static void variadics( char * ptr, const Head & head, const Tail & ... tail ) {
        *static_cast<Head *>(reinterpret_cast<void*>(ptr)) = head;
        ptr += sizeof(Head);
        variadics1( ptr, tail... );
    }
    static void variadics( char * ) {}
};

__END_API
#endif
