#ifndef __skeleton_h
#define __skeleton_h

#include <stub/message.h>

__BEGIN_SYS

class Skeleton {

public:
	static void call(Message *);
	
private:
	// Condition
	static void condition_constructor(Message * m);
	static void condition_destrutor(Message * m);
	static void condition_wait(Message * m);
	static void condition_signal(Message * m);
	static void condition_broadcast(Message * m);
	
	// Semaphore
	static void semaphore_constructor(Message * m);
	static void semaphore_destrutor(Message * m);
	static void semaphore_p(Message * m);
	static void semaphore_v(Message * m);
	
	// Mutex
	static void mutex_constructor(Message * m);
	static void mutex_destrutor(Message * m);
	static void mutex_lock(Message * m);	
	static void mutex_unlock(Message * m);
	
	// Task
	static void task_constructor(Message * m);
	static void task_destrutor(Message * m);
	static void task_address_space(Message * m);
	static void task_code_segment(Message * m);
	static void task_code(Message * m);
	static void task_data_segment(Message * m);
	static void task_data(Message * m);
	static void task_self(Message * m);
};

__END_SYS
#endif