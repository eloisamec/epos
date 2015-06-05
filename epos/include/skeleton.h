#ifndef __skeleton_h
#define __skeleton_h

__BEGIN_SYS

#include <message.h>
#include <system/config.h>

class Skeleton {

public:
	static void call(Message *);
	
private:
	// Semaphore
	static void semaphore_constructor(Message *);
	static void semaphore_destrutor(Message *);
	static void semaphore_p(Message *);
	static void semaphore_v(Message *);
	
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