#ifndef __skeleton_h
#define __skeleton_h

#include <stub/message.h>

__BEGIN_SYS

class Skeleton {

public:
	static void call(Message * m);
	
private:
	// Address Space
	static void address_space_constructor_1(Message * m);
	static void address_space_constructor_2(Message * m);
	static void address_space_destructor(Message * m);
	static void address_space_attach_1(Message * m);
	static void address_space_attach_2(Message * m);
	static void address_space_detach(Message * m);
	static void address_space_physical(Message * m);

	// Alarm
	static void alarm_constructor(Message * m);
	static void alarm_destructor(Message * m);
	static void alarm_frequency(Message * m);
	static void alarm_delay(Message * m);
	
	// Condition
	static void condition_constructor(Message * m);
	static void condition_destructor(Message * m);
	static void condition_wait(Message * m);
	static void condition_signal(Message * m);
	static void condition_broadcast(Message * m);
	
	// Display
	static void display_constructor(Message * m);
	static void display_clear(Message * m);
	static void display_putc(Message * m);
	static void display_puts(Message * m);
	static void display_geometry(Message * m);
	static void display_position_1(Message * m);
	static void display_position_2(Message * m);
	
	// Handler
	static void handler_constructor(Message * m);
	static void handler_destructor(Message * m);
	
	// Mutex
	static void mutex_constructor(Message * m);
	static void mutex_destructor(Message * m);
	static void mutex_lock(Message * m);	
	static void mutex_unlock(Message * m);
	
	// Ostream
	static void ostream_constructor(Message * m);
	static void ostream_operator_1(Message * m);
	static void ostream_operator_2(Message * m);
	static void ostream_operator_3(Message * m);
	static void ostream_operator_4(Message * m);
	static void ostream_operator_5(Message * m);
	static void ostream_operator_6(Message * m);
	static void ostream_operator_7(Message * m);
	static void ostream_operator_8(Message * m);
	static void ostream_operator_9(Message * m);
	static void ostream_operator_10(Message * m);
	static void ostream_operator_11(Message * m);
	static void ostream_operator_12(Message * m);
	static void ostream_operator_13(Message * m);
	static void ostream_operator_14(Message * m);
	static void ostream_operator_15(Message * m);
	static void ostream_operator_16(Message * m);
	static void ostream_operator_17(Message * m);
	static void ostream_operator_18(Message * m);
	static void ostream_operator_19(Message * m);
	static void ostream_operator_20(Message * m);
	static void ostream_operator_21(Message * m);

	// Segment
	static void segment_constructor_1(Message * m);
	static void segment_constructor_2(Message * m);
	static void segment_destructor(Message * m);
	static void segment_size(Message * m);
	static void segment_phy_address(Message * m);
	static void segment_resize(Message * m);
		
	// Semaphore
	static void semaphore_constructor(Message * m);
	static void semaphore_destructor(Message * m);
	static void semaphore_p(Message * m);
	static void semaphore_v(Message * m);
	
	// Task
	static void task_constructor(Message * m);
	static void task_destructor(Message * m);
	static void task_address_space(Message * m);
	static void task_code_segment(Message * m);
	static void task_code(Message * m);
	static void task_data_segment(Message * m);
	static void task_data(Message * m);
	static void task_self(Message * m);
	
	// Thread
	template<typename T>
	static void thread_constructor_1(Message * m);
	template<typename T1, typename T2>
	static void thread_constructor_2(Message * m);
	template<typename T1, typename T2, typename T3>
	static void thread_constructor_3(Message * m);
	template<typename T1, typename T2, typename T3, typename T4>
	static void thread_constructor_4(Message * m);
	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	static void thread_constructor_5(Message * m);
	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	static void thread_constructor_6(Message * m);
	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	static void thread_constructor_7(Message * m);
	static void thread_destructor(Message * m);
	static void thread_state(Message * m);
	static void thread_priority_1(Message * m);
	static void thread_priority_2(Message * m);
	static void thread_task(Message * m);
	static void thread_join(Message * m);
	static void thread_pass(Message * m);
	static void thread_suspend(Message * m);
	static void thread_resume(Message * m);
	static void thread_self(Message * m);
	static void thread_yield(Message * m);
	static void thread_exit(Message * m);
};

__END_SYS
#endif
