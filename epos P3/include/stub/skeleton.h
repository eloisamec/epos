#ifndef __Skeleton_h
#define __Skeleton_h

#include <system/config.h>
#include <ic.h>
#include <stub/message.h>

__BEGIN_SYS

class Skeleton {

public:
    static void call(int *);
    static void receive();

private:
    static void semaphore_constructor(int *);
    static void semaphore_destructor(int *);
    static void semaphore_p(int *);
    static void semaphore_v(int *);

    static void mutex_constructor(int *);
    static void mutex_destructor(int *);
    static void mutex_lock(int *);
    static void mutex_unlock(int *);

    static void alarm_constructor(int *);
    static void alarm_destructor(int *);
    static void alarm_frequency(int *);
    static void alarm_delay(int *);

    static void condition_constructor(int *);
    static void condition_destructor(int *);
    static void condition_wait(int *);
    static void condition_signal(int *);
    static void condition_broadcast(int *);

    static void function_handler_constructor(int *);
    static void function_handler_destructor(int *);
    static void function_handler_call(int *);

    static void semaphore_handler_constructor(int *);
    static void semaphore_handler_destructor(int *);
    static void semaphore_handler_call(int *);

    static void mutex_handler_constructor(int *);
    static void mutex_handler_destructor(int *);
    static void mutex_handler_call(int *);

    static void condition_handler_constructor(int *);
    static void condition_handler_destructor(int *);
    static void condition_handler_call(int *);

    static void thread_handler_constructor(int *);
    static void thread_handler_destructor(int *);
    static void thread_handler_call(int *);

    static void thread_constructor_0(int *);
    static void thread_constructor_1(int *);
    static void thread_constructor_2(int *);
    static void thread_constructor_3(int *);
    static void thread_constructor_4(int *);
    static void thread_constructor_5(int *);
    static void thread_constructor_6(int *);
    static void thread_constructor_t_0(int *);
    static void thread_constructor_t_1(int *);
    static void thread_constructor_t_2(int *);
    static void thread_constructor_t_3(int *);
    static void thread_constructor_t_4(int *);
    static void thread_constructor_t_5(int *);
    static void thread_constructor_c_0(int *);
    static void thread_constructor_c_1(int *);
    static void thread_constructor_c_2(int *);
    static void thread_constructor_c_3(int *);
    static void thread_constructor_c_4(int *);
    static void thread_constructor_c_5(int *);
    static void thread_constructor_tc_0(int *);
    static void thread_constructor_tc_1(int *);
    static void thread_constructor_tc_2(int *);
    static void thread_constructor_tc_3(int *);
    static void thread_constructor_tc_4(int *);
    static void thread_destructor(int *);
    static void thread_state(int *);
    static void thread_get_priority(int *);
    static void thread_set_priority(int *);
    static void thread_task(int *);
    static void thread_join(int *);
    static void thread_pass(int *);
    static void thread_suspend(int *);
    static void thread_resume(int *);
    static void thread_self(int *);
    static void thread_yield(int *);
    static void thread_exit(int *);

    static void delay_constructor(int *);

    static void address_space_constructor_1(int *);
    static void address_space_constructor_2(int *);
    static void address_space_destructor(int *);
    static void address_space_attach_1(int *);
    static void address_space_attach_2(int *);
    static void address_space_detach(int *);
    static void address_space_physical(int *);
    static void address_space_pd(int *);

    static void segment_constructor_1(int *);
    static void segment_constructor_2(int *);
    static void segment_destructor(int *);
    static void segment_size(int *);
    static void segment_phy_address(int *);
    static void segment_resize(int *);

    static void task_constructor(int *);
    static void task_destructor(int *);
    static void task_address_space(int *);
    static void task_code_segment(int *);
    static void task_code(int *);
    static void task_data_segment(int *);
    static void task_data(int *);
    static void task_self(int *);

    static void ostream_constructor(int *);
    static void ostream_destructor(int *);
    static void ostream_begl(int *);
    static void ostream_endl(int *);
    static void ostream_hex(int *);
    static void ostream_dec(int *);
    static void ostream_oct(int *);
    static void ostream_bin(int *);
    static void ostream_err(int *);
    static void ostream_char(int *);
    static void ostream_uchar(int *);
    static void ostream_int(int *);
    static void ostream_short(int *);
    static void ostream_long(int *);
    static void ostream_uint(int *);
    static void ostream_ushort(int *);
    static void ostream_ulong(int *);
    static void ostream_llint(int *);
    static void ostream_ullint(int *);
    static void ostream_void_ptr(int *);
    static void ostream_char_ptr(int *);
    static void ostream_float(int *);


};

__END_SYS

#endif
