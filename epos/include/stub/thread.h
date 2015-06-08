#ifndef __thread_h
#define __thread_h

#include <app_types.h>
#include <stub/message.h>
#include <stub/skeleton.h>

__BEGIN_APP

class Thread {

public:
	template<typename ... Tn>
	Thread(int (*entry)(Tn ...), Tn ... an) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_1);
		message->variadic1((void*) (*entry)...);
		message->variadic2((void*) an...);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename ... Tn>
	Thread(Task * task, int (*entry)(Tn ...), Tn ... an) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_2);
		message->param1((void*) task);
		message->variadic1((void*) (*entry)...);
		message->variadic2((void*) an...);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename ... Cn, typename ... Tn>
	Thread(const Configuration & conf, int (*entry)(Tn ...), Tn ... an) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_3);
		message->param1((void*) conf);
		message->variadic1((void*) (*entry)...);
		message->variadic2((void*) an...);
    	Skeleton::call(message);
    	_obj_id = message->return_value();
	}
	
	template<typename ... Cn, typename ... Tn>
	Thread(const Configuration & conf, Task * task, int (*entry)(Tn ...), Tn ... an) {
		message = new Message();
    	message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::CONSTRUCTOR_4);
		message->param1((void*) conf);
		message->param2((void*) task);
		message->variadic1((void*) (*entry)...);
		message->variadic2((void*) an...);
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
	
	const volatile State & state () const {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::STATE);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Thread * thread = reinterpret_cast<Thread *> message->return_value();
		return thread->_state;
	}
	
	const volatile Priority & priority() const {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::PRIORITY_1);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Thread * thread = reinterpret_cast<Thread *> message->return_value();
		return thread->_link.rank();
	}
	
	void priority(const Priority & p) {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::PRIORITY_2);
    	message->object_id(_obj_id);
    	message->param1((void*) p);
    	Skeleton::call(message);
	}
	
	Task * task() const {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::TASK);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Task * task = reinterpret_cast<Task *> message->return_value();
		return const_cast<Task*>(task);
	}
	
	int join() {
		message->class_id(Class::THREAD);
    	message->method_id(Method::Thread::JOIN);
    	message->object_id(_obj_id);
    	Skeleton::call(message);
		Thread * thread = reinterpret_cast<Thread *> message->return_value();
		return thread->join();
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
	
	static Thread & volatile self() {
		Message message = Message();
		message.class_id(Class::THREAD);
    	message.method_id(Method::Thread::SELF);
    	message.object_id(_obj_id);
    	Skeleton::call(message);
		Thread * thread = reinterpret_cast<Thread *> message->return_value();
		return thread->running();
	}
	
	static void yield() {
		Message message = Message();
		message.class_id(Class::THREAD);
    	message.method_id(Method::Thread::YIELD);
    	message.object_id(_obj_id);
    	Skeleton::call(message);
	}
	
	static void exit(int status) {
		Message message = Message();
		message.class_id(Class::THREAD);
    	message.method_id(Method::Thread::EXIT);
    	message.param1((void*) status);
    	message.object_id(_obj_id);
    	Skeleton::call(message);
	}
	
private:
	void * _obj_id;
	Message * message;
};

__END_APP
#endif
