#ifndef __skeleton_h
#define __skeleton_h

#include <stub/message.h>

__BEGIN_SYS

class Skeleton {

public:
	static void call(Message * m);
	
	// Semaphore
	static void semaphore_constructor(Message * m);
	static void semaphore_destrutor(Message * m);
	static void semaphore_p(Message * m);
	static void semaphore_v(Message * m);
	
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