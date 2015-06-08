#ifndef __thread_h
#define __thread_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>
#include <scheduler.h>

__BEGIN_APP

class Thread {

private:
	enum State {
        RUNNING,
        READY,
        SUSPENDED,
        WAITING,
        FINISHING
    };
	
	typedef Scheduling_Criteria::Priority Priority;

public:
	template<typename T>
	Thread(T t1) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_1);
		message->param1((void *) t1);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename T1, typename T2>
	Thread(T1 t1, T2 t2) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_2);
		message->param1((void *) t1);
		message->param2((void *) t2);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename T1, typename T2, typename T3>
	Thread(T1 t1, T2 t2, T3 t3) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_3);
    	message->param1((void *) t1);
		message->param2((void *) t2);
		message->param3((void *) t3);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename T1, typename T2, typename T3, typename T4>
	Thread(T1 t1, T2 t2, T3 t3, T4 t4) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_4);
		message->param1((void *) t1);
		message->param2((void *) t2);
		message->param3((void *) t3);
		message->param4((void *) t4);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	Thread(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_5);
		message->param1((void *) t1);
		message->param2((void *) t2);
		message->param3((void *) t3);
		message->param4((void *) t4);
		message->param5((void *) t5);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	Thread(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_6);
		message->param1((void *) t1);
		message->param2((void *) t2);
		message->param3((void *) t3);
		message->param4((void *) t4);
		message->param5((void *) t5);
		message->param6((void *) t6);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	Thread(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_7);
		message->param1((void *) t1);
		message->param2((void *) t2);
		message->param3((void *) t3);
		message->param4((void *) t4);
		message->param5((void *) t5);
		message->param6((void *) t6);
		message->param7((void *) t7);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	~Thread() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::DESTRUCTOR);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		delete message;
	}
	
	const volatile State & state() const {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::STATE);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		return *reinterpret_cast<State *>(message->return_value());
	}
	
	const volatile Priority & priority() const {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::PRIORITY_1);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		return *reinterpret_cast<Priority *>(message->return_value());
	}
	
	void priority(const Priority & p) {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::PRIORITY_2);
    	message->object_id(_obj_id);
    	message->param1((void*) &p);
    	Skeleton::call(message);
	}
	
	Task * task() const {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::TASK);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Task * task = reinterpret_cast<Task *>(message->return_value());
		return const_cast<Task*>(task);
	}
	
	int join() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::JOIN);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		int join = *reinterpret_cast<int *>(message->return_value());
		return join;
	}
	
	void pass() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::PASS);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
	void suspend() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::SUSPEND);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
	void resume() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::RESUME);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
	}
	
	static Thread & self() {
		Message message = Message();
		message.class_id(Class::THREAD);
    	message.method_id(Method::Thread::SELF);
    	Skeleton::call(&message);
		return *reinterpret_cast<Thread *>(message.return_value());
	}
	
	static void yield() {
		Message message = Message();
		message.class_id(Class::THREAD);
    	message.method_id(Method::Thread::YIELD);
    	Skeleton::call(&message);
	}
	
	static void exit(int status) {
		Message message = Message();
		message.class_id(Class::THREAD);
    	message.method_id(Method::Thread::EXIT);
    	message.param1((void*) status);
    	Skeleton::call(&message);
	}
	
private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif
