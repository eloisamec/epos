#include <utility/ostream.h>
#include <stub/skeleton.h>
#include <api_types.h>

#include <address_space.h>
#include <alarm.h>
#include <condition.h>
#include <mutex.h>
#include <semaphore.h>
#include <thread.h>

__BEGIN_SYS

typedef CPU_Common::Reg32 Reg32;

void Skeleton::call(int * m){
    int class_id = m[0];
    int method_id = m[1];

    switch (class_id) {
    case APPLICATION::Class::ADDRESS_SPACE:
        switch(method_id){
        case APPLICATION::Method::Address_Space::CONSTRUCTOR_1: address_space_constructor_1(m); break;
        case APPLICATION::Method::Address_Space::CONSTRUCTOR_2: address_space_constructor_2(m); break;
        case APPLICATION::Method::Address_Space::DESTRUCTOR:    address_space_destructor(m);    break;
        case APPLICATION::Method::Address_Space::ATTACH_1:      address_space_attach_1(m);      break;
        case APPLICATION::Method::Address_Space::ATTACH_2:      address_space_attach_2(m);      break;
        case APPLICATION::Method::Address_Space::SIZE:          address_space_detach(m);        break;
        case APPLICATION::Method::Address_Space::PHYSICAL:      address_space_physical(m);      break;
        case APPLICATION::Method::Address_Space::PD:            address_space_pd(m);            break;
        }
        break;
    case APPLICATION::Class::ALARM:
        switch(method_id){
        case APPLICATION::Method::Alarm::CONSTRUCTOR: alarm_constructor(m); break;
        case APPLICATION::Method::Alarm::DESTRUCTOR:  alarm_destructor(m);  break;
        case APPLICATION::Method::Alarm::FREQUENCY:   alarm_frequency(m);   break;
        case APPLICATION::Method::Alarm::DELAY:       alarm_delay(m);       break;
        }
        break;
    case APPLICATION::Class::CONDITION:
        switch(method_id){
        case APPLICATION::Method::Condition::CONSTRUCTOR: condition_constructor(m); break;
        case APPLICATION::Method::Condition::DESTRUCTOR:  condition_destructor(m);   break;
        case APPLICATION::Method::Condition::WAIT:        condition_wait(m);         break;
        case APPLICATION::Method::Condition::_SIGNAL:     condition_signal(m);       break;
        case APPLICATION::Method::Condition::BROADCAST:   condition_broadcast(m);    break;
        }
        break;
    case APPLICATION::Class::CONDITION_HANDLER:
        switch(method_id){
        case APPLICATION::Method::Handler::CONSTRUCTOR: condition_handler_constructor(m); break;
        case APPLICATION::Method::Handler::DESTRUCTOR:  condition_handler_destructor(m);  break;
        case APPLICATION::Method::Handler::CALL:   	    condition_handler_call(m);        break;
        }
        break;

    case APPLICATION::Class::MUTEX:
        switch(method_id){
        case APPLICATION::Method::Mutex::CONSTRUCTOR: mutex_constructor(m); break;
        case APPLICATION::Method::Mutex::DESTRUCTOR:  mutex_destructor(m);  break;
        case APPLICATION::Method::Mutex::LOCK:        mutex_lock(m);  break;
        case APPLICATION::Method::Mutex::UNLOCK:      mutex_unlock(m);  break;
        }
        break;
    case APPLICATION::Class::MUTEX_HANDLER:
        switch(method_id){
        case APPLICATION::Method::Handler::CONSTRUCTOR: mutex_handler_constructor(m); break;
        case APPLICATION::Method::Handler::DESTRUCTOR:  mutex_handler_destructor(m);  break;
        case APPLICATION::Method::Handler::CALL:   	    mutex_handler_call(m);        break;
        }
        break;

    case APPLICATION::Class::SEMAPHORE:
        switch(method_id){
        case APPLICATION::Method::Semaphore::CONSTRUCTOR: semaphore_constructor(m); break;
        case APPLICATION::Method::Semaphore::DESTRUCTOR:  semaphore_destructor(m);  break;
        case APPLICATION::Method::Semaphore::P:           semaphore_p(m);  break;
        case APPLICATION::Method::Semaphore::V:           semaphore_v(m);  break;
        }
        break;
    case APPLICATION::Class::SEMAPHORE_HANDLER:
        switch(method_id){
        case APPLICATION::Method::Handler::CONSTRUCTOR: semaphore_handler_constructor(m); break;
        case APPLICATION::Method::Handler::DESTRUCTOR:  semaphore_handler_destructor(m);  break;
        case APPLICATION::Method::Handler::CALL:   	   semaphore_handler_call(m);        break;
        }
        break;

    case APPLICATION::Class::DELAY:
        switch(method_id){
        case APPLICATION::Method::Delay::CONSTRUCTOR: delay_constructor(m); break;
        }
        break;
    case APPLICATION::Class::OSTREAM:
        switch(method_id){
        case APPLICATION::Method::OStream::CONSTRUCTOR: ostream_constructor(m); break;
        case APPLICATION::Method::OStream::DESTRUCTOR:  ostream_destructor(m);  break;
        case APPLICATION::Method::OStream::CHAR_PTR:    ostream_char_ptr(m);    break;
        case APPLICATION::Method::OStream::BEGL:        ostream_begl(m);        break;
        case APPLICATION::Method::OStream::ENDL:        ostream_endl(m);        break;
        case APPLICATION::Method::OStream::HEX:         ostream_hex(m);         break;
        case APPLICATION::Method::OStream::DEC:         ostream_dec(m);         break;
        case APPLICATION::Method::OStream::OCT:         ostream_oct(m);         break;
        case APPLICATION::Method::OStream::BIN:         ostream_bin(m);         break;
        case APPLICATION::Method::OStream::ERR:         ostream_err(m);         break;
        case APPLICATION::Method::OStream::CHAR:        ostream_char(m);        break;
        case APPLICATION::Method::OStream::UCHAR:       ostream_uchar(m);       break;
        case APPLICATION::Method::OStream::INT:         ostream_int(m);         break;
        case APPLICATION::Method::OStream::SHORT:       ostream_short(m);       break;
        case APPLICATION::Method::OStream::LONG:        ostream_long(m);        break;
        case APPLICATION::Method::OStream::UINT:        ostream_uint(m);        break;
        case APPLICATION::Method::OStream::USHORT:      ostream_ushort(m);      break;
        case APPLICATION::Method::OStream::ULONG:       ostream_ulong(m);       break;
        case APPLICATION::Method::OStream::LLINT:       ostream_llint(m);       break;
        case APPLICATION::Method::OStream::ULLINT:      ostream_ullint(m);      break;
        case APPLICATION::Method::OStream::VOID_PTR:    ostream_void_ptr(m);    break;
        case APPLICATION::Method::OStream::FLOAT:       ostream_float(m);       break;
        }
        break;
    case APPLICATION::Class::SEGMENT:
        switch(method_id){
        case APPLICATION::Method::Segment::CONSTRUCTOR_1: segment_constructor_1(m); break;
        case APPLICATION::Method::Segment::CONSTRUCTOR_2: segment_constructor_2(m); break;
        case APPLICATION::Method::Segment::DESTRUCTOR:    segment_destructor(m);    break;
        case APPLICATION::Method::Segment::SIZE:          segment_size(m);          break;
        case APPLICATION::Method::Segment::RESIZE:        segment_resize(m);        break;
        case APPLICATION::Method::Segment::PHY_ADDRESS:   segment_phy_address(m);   break;
        }
        break;
    case APPLICATION::Class::TASK:
        switch(method_id){
        case APPLICATION::Method::Task::CONSTRUCTOR:    task_constructor(m);      break;
        case APPLICATION::Method::Task::DESTRUCTOR:     task_destructor(m);       break;
        case APPLICATION::Method::Task::ADDRESS_SPACE:  task_address_space(m);    break;
        case APPLICATION::Method::Task::CODE_SEGMENT:   task_code_segment(m);     break;
        case APPLICATION::Method::Task::CODE:           task_code(m);             break;
        case APPLICATION::Method::Task::DATA_SEGMENT:   task_data_segment(m);     break;
        case APPLICATION::Method::Task::DATA:           task_data(m);             break;
        case APPLICATION::Method::Task::SELF:           task_self(m);             break;
        }
        break;
    case APPLICATION::Class::THREAD:
        switch(method_id){
        case APPLICATION::Method::Thread::CONSTRUCTOR_0: thread_constructor_0(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_1: thread_constructor_1(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_2: thread_constructor_2(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_3: thread_constructor_3(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_4: thread_constructor_4(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_5: thread_constructor_5(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_6: thread_constructor_6(m); break;

        case APPLICATION::Method::Thread::CONSTRUCTOR_T_0: thread_constructor_t_0(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_T_1: thread_constructor_t_1(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_T_2: thread_constructor_t_2(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_T_3: thread_constructor_t_3(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_T_4: thread_constructor_t_4(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_T_5: thread_constructor_t_5(m); break;

        case APPLICATION::Method::Thread::CONSTRUCTOR_C_0: thread_constructor_c_0(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_C_1: thread_constructor_c_1(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_C_2: thread_constructor_c_2(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_C_3: thread_constructor_c_3(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_C_4: thread_constructor_c_4(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_C_5: thread_constructor_c_5(m); break;

        case APPLICATION::Method::Thread::CONSTRUCTOR_TC_0: thread_constructor_tc_0(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_TC_1: thread_constructor_tc_1(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_TC_2: thread_constructor_tc_2(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_TC_3: thread_constructor_tc_3(m); break;
        case APPLICATION::Method::Thread::CONSTRUCTOR_TC_4: thread_constructor_tc_4(m); break;

        case APPLICATION::Method::Thread::DESTRUCTOR:    thread_destructor(m);    break;
        case APPLICATION::Method::Thread::STATE:         thread_state(m);         break;
        case APPLICATION::Method::Thread::GET_PRIORITY:  thread_get_priority(m);  break;
        case APPLICATION::Method::Thread::SET_PRIORITY:  thread_set_priority(m);  break;
        case APPLICATION::Method::Thread::TASK:          thread_task(m);          break;
        case APPLICATION::Method::Thread::JOIN:          thread_join(m);          break;
        case APPLICATION::Method::Thread::PASS:          thread_pass(m);          break;
        case APPLICATION::Method::Thread::SUSPEND:       thread_suspend(m);       break;
        case APPLICATION::Method::Thread::RESUME:        thread_resume(m);        break;
        case APPLICATION::Method::Thread::SELF:          thread_self(m);          break;
        case APPLICATION::Method::Thread::YIELD:         thread_yield(m);         break;
        case APPLICATION::Method::Thread::EXIT:          thread_exit(m);          break;
        }
        break;
    case APPLICATION::Class::THREAD_HANDLER:
        switch(method_id){
        case APPLICATION::Method::Handler::CONSTRUCTOR: thread_handler_constructor(m); break;
        case APPLICATION::Method::Handler::DESTRUCTOR:  thread_handler_destructor(m);  break;
        case APPLICATION::Method::Handler::CALL:        thread_handler_call(m);        break;
        }
        break;

    default:
        ASM("iret"); // Feito para dar erro - Não selecionou nenhuma classe valida
        break;
    }

}

// ADDRESS SPACE

void Skeleton::address_space_constructor_1(int * m){
    Address_Space * as = new (SYSTEM) Address_Space();
    m[2] = reinterpret_cast<int>(as);
}

void Skeleton::address_space_constructor_2(int * m){
    IA32_MMU::Page_Directory * pd = reinterpret_cast<IA32_MMU::Page_Directory*>(m[4]);
    Address_Space * as = new (SYSTEM) Address_Space(pd);
    m[2] = reinterpret_cast<int>(as);
}

void Skeleton::address_space_destructor(int * m){
    Address_Space * as = reinterpret_cast<Address_Space*>(m[2]);
    delete as;
}

void Skeleton::address_space_attach_1(int * m){
    Address_Space * as = reinterpret_cast<Address_Space *>(m[2]);
    Segment & sg = *reinterpret_cast<Segment*>(m[4]);
    Address_Space::Log_Addr log_addr = as->attach(sg);
//    Address_Space::Log_Addr * lad = new Address_Space::Log_Addr(log_addr); // Salva o objeto na heap
    m[3] = reinterpret_cast<int>(&log_addr);
}

void Skeleton::address_space_attach_2(int * m){
    Address_Space * as = reinterpret_cast<Address_Space*>(m[2]);
    Segment & sg = *reinterpret_cast<Segment *>(m[4]);
    Address_Space::Log_Addr laddr = *reinterpret_cast<Address_Space::Log_Addr*>(m[5]);
    Address_Space::Log_Addr log_addr = as->attach(sg, laddr);
    m[3] = reinterpret_cast<int>(&log_addr);
}

void Skeleton::address_space_detach(int * m){
    Address_Space * as = reinterpret_cast<Address_Space*>(m[2]);
    Segment sg = *reinterpret_cast<Segment*>(m[4]);
    as->detach(sg);
}

void Skeleton::address_space_physical(int* m){
    Address_Space * as = reinterpret_cast<Address_Space*>(m[2]);
    Address_Space::Log_Addr log_addr = *reinterpret_cast<Address_Space::Log_Addr*>(m[4]);
    Address_Space::Phy_Addr phy_addr = as->physical(log_addr);
    m[3] = reinterpret_cast<int>(&phy_addr);
}

void Skeleton::address_space_pd(int* m){
    Address_Space * as = reinterpret_cast<Address_Space*>(m[2]);
    Address_Space::Phy_Addr phy_addr = as->pd();
    m[3] = reinterpret_cast<int>(&phy_addr);
}


// ALARM

void Skeleton::alarm_constructor(int * m){
    Alarm::Microsecond time = *reinterpret_cast<Alarm::Microsecond*>(m[4]);
    Handler::Function * handler = reinterpret_cast<Handler::Function*>(m[5]);
    Function_Handler * fh = new (SYSTEM) Function_Handler(handler);
    int times = m[6];
    Alarm * al = new (SYSTEM) Alarm(time, fh, times);
    m[3] = *reinterpret_cast<int*>(al);
}

void Skeleton::alarm_destructor(int * m){
    Alarm * alarm = reinterpret_cast<Alarm*>(m[2]);
    delete alarm;
}

void Skeleton::alarm_frequency(int * m){
    Alarm * alarm = reinterpret_cast<Alarm*>(m[2]);
    m[3] = *reinterpret_cast<int*>(alarm->frequency());
}

void Skeleton::alarm_delay(int * m){
    Alarm * alarm = reinterpret_cast<Alarm*>(m[2]);
    Alarm::Microsecond time = *reinterpret_cast<Alarm::Microsecond*>(m[4]);
    alarm->delay(time);
}


// FUNCTION_HANDLER


void Skeleton::function_handler_constructor(int * m){
    Handler::Function * function = reinterpret_cast<Handler::Function*>(m[4]);
    Function_Handler * fh = new (SYSTEM) Function_Handler(function);
    m[3] = reinterpret_cast<int>(fh);
}

void Skeleton::function_handler_destructor(int * m){
    Function_Handler * fh = reinterpret_cast<Function_Handler*>(m[2]);
    delete fh;
}

void Skeleton::function_handler_call(int * m){
    Function_Handler * fh = reinterpret_cast<Function_Handler*>(m[2]);
    (*fh)();
}

// CONDITION

void Skeleton::condition_constructor(int * m){
    Condition * condition = new (SYSTEM) Condition();
    m[2] = reinterpret_cast<int>(condition);
}

void Skeleton::condition_destructor(int * m){
    Condition * condition = reinterpret_cast<Condition*>(m[2]);
    delete condition;
}

void Skeleton::condition_wait(int * m){
    Condition* condition = reinterpret_cast<Condition*>(m[2]);
    condition->wait();
}

void Skeleton::condition_signal(int * m){
    Condition * condition = reinterpret_cast<Condition*>(m[2]);
    condition->signal();
}

void Skeleton::condition_broadcast(int * m){
    Condition* condition = reinterpret_cast<Condition*>(m[2]);
    condition->broadcast();
}


// CONDITION HANDLER

void Skeleton::condition_handler_constructor(int * m){
    Condition * condition = reinterpret_cast<Condition*>(m[4]);
    m[2] = reinterpret_cast<int>(new (SYSTEM) Condition_Handler(condition));
}

void Skeleton::condition_handler_destructor(int * m){
    Condition_Handler * condition_handler = reinterpret_cast<Condition_Handler*>(m[2]);
    delete condition_handler;
}

void Skeleton::condition_handler_call(int * m){
    Condition_Handler * condition_handler = reinterpret_cast<Condition_Handler*>(m[4]);
    (*condition_handler)();
}

// SEMAPHORE

void Skeleton::semaphore_constructor(int * m){
    Semaphore * semaphore = new (SYSTEM) Semaphore(m[4]);
    m[2] = reinterpret_cast<int>(semaphore);
}

void Skeleton::semaphore_destructor(int * m){
    Semaphore * semaphore = reinterpret_cast<Semaphore*>(m[2]);
    delete semaphore;
}

void Skeleton::semaphore_p(int * m){
    Semaphore * semaphore = reinterpret_cast<Semaphore*>(m[2]);
    semaphore->p();
}

void Skeleton::semaphore_v(int * m){
    Semaphore * semaphore = reinterpret_cast<Semaphore*>(m[2]);
    semaphore->v();
}

// MUTEX

void Skeleton::mutex_constructor(int * m){
    Mutex * mutex = new (SYSTEM) Mutex();
    m[2] = reinterpret_cast<int>(mutex);
}

void Skeleton::mutex_destructor(int * m){
    Mutex * mutex = reinterpret_cast<Mutex*>(m[2]);
    delete mutex;
}

void Skeleton::mutex_lock(int * m){
    Mutex * mutex = reinterpret_cast<Mutex*>(m[2]);
    mutex->lock();
}

void Skeleton::mutex_unlock(int * m){
    Mutex * mutex = reinterpret_cast<Mutex*>(m[2]);
    mutex->unlock();
}


// SEMAPHORE HANDLER

void Skeleton::semaphore_handler_constructor(int * m){
    Semaphore * s = reinterpret_cast<Semaphore*>(m[4]);
    m[2] = reinterpret_cast<int>(new (SYSTEM) Semaphore_Handler(s));
}

void Skeleton::semaphore_handler_destructor(int * m){
    Semaphore_Handler * sh = reinterpret_cast<Semaphore_Handler*>(m[2]);
    delete sh;
}


void Skeleton::semaphore_handler_call(int * m){
    Semaphore_Handler * sh = reinterpret_cast<Semaphore_Handler*>(m[2]);
    (*sh)();
}


// MUTEX HANDLER

void Skeleton::mutex_handler_constructor(int * m){
    Mutex * mutex = reinterpret_cast<Mutex*>(m[4]);
    m[2] = reinterpret_cast<int>(new (SYSTEM) Mutex_Handler(mutex));
}

void Skeleton::mutex_handler_destructor(int * m){
    Mutex_Handler * mutex_handler = reinterpret_cast<Mutex_Handler*>(m[2]);
    delete mutex_handler;
}


void Skeleton::mutex_handler_call(int * m){
    Mutex_Handler * mutex_handler = reinterpret_cast<Mutex_Handler*>(m[2]);
    (*mutex_handler)();
}


// THREAD HANDLER

void Skeleton::thread_handler_constructor(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[4]);
    Thread_Handler * thread_handler = new (SYSTEM) Thread_Handler(thread);
    m[2] = reinterpret_cast<int>(thread_handler);
}

void Skeleton::thread_handler_destructor(int * m){
    Thread_Handler * thread_handler = reinterpret_cast<Thread_Handler*>(m[2]);
    delete thread_handler;
}

void Skeleton::thread_handler_call(int * m){
    Thread_Handler * thread_handler = reinterpret_cast<Thread_Handler*>(m[2]);
    (*thread_handler)();
}


// DELAY

void Skeleton::delay_constructor(int * m){
    Delay::Delay(*reinterpret_cast<Delay::Microsecond*>(m[4]));
}


// THREAD

void Skeleton::thread_self(int * m){
    m[3] = reinterpret_cast<int>(Thread::self());
}

void Skeleton::thread_constructor_0(int * m){
    typedef int (Entry)();
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_1(int * m){
    typedef int (Entry)(int);
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry, m[5]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_2(int * m){
    typedef int (Entry)(int, int);
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry, m[5], m[6]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_3(int * m){
    typedef int (Entry)(int, int, int);
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry, m[5], m[6], m[7]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_4(int * m){
    typedef int (Entry)(int, int, int, int);
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry, m[5], m[6], m[7], m[8]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_5(int * m){
    typedef int (Entry)(int, int, int, int, int);
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry, m[5], m[6], m[7], m[8], m[9]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_6(int * m){
    typedef int (Entry)(int, int, int, int, int, int);
    Entry * entry = reinterpret_cast<Entry*>(m[4]);
    Thread * thread = new (SYSTEM) Thread(entry, m[5], m[6], m[7], m[8], m[9], m[10]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_t_0(int * m){
    typedef int (Entry)();
    Task * task =reinterpret_cast<Task*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(task, entry);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_t_1(int * m){
    typedef int (Entry)(int);
    Task * task =reinterpret_cast<Task*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(task, entry, m[6]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_t_2(int * m){
    typedef int (Entry)(int, int);
    Task * task =reinterpret_cast<Task*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(task, entry, m[6], m[7]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_t_3(int * m){
    typedef int (Entry)(int, int, int);
    Task * task =reinterpret_cast<Task*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(task, entry, m[6], m[7], m[8]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_t_4(int * m){
    typedef int (Entry)(int, int, int, int);
    Task * task =reinterpret_cast<Task*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(task, entry, m[6], m[7], m[8], m[9]);
    m[3] = reinterpret_cast<int>(thread);
}


void Skeleton::thread_constructor_t_5(int * m){
    typedef int (Entry)(int, int, int, int, int);
    Task * task =reinterpret_cast<Task*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(task, entry, m[6], m[7], m[8], m[9], m[10]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_c_0(int * m){
    typedef int (Entry)();
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(conf, entry);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_c_1(int * m){
    typedef int (Entry)(int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(conf, entry, m[6]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_c_2(int * m){
    typedef int (Entry)(int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(conf, entry, m[6], m[7]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_c_3(int * m){
    typedef int (Entry)(int, int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(conf, entry, m[6], m[7], m[8]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_c_4(int * m){
    typedef int (Entry)(int, int, int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(conf, entry, m[6], m[7], m[8], m[9]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_c_5(int * m){
    typedef int (Entry)(int, int, int, int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Entry * entry = reinterpret_cast<Entry*>(m[5]);
    Thread * thread = new (SYSTEM) Thread(conf, entry, m[6], m[7], m[8], m[9], m[10]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_tc_0(int * m){
    typedef int (Entry)();
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Task * task = reinterpret_cast<Task*>(m[5]);
    Entry * entry = reinterpret_cast<Entry*>(m[6]);
    Thread * thread = new (SYSTEM) Thread(conf, task, entry);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_tc_1(int * m){
    typedef int (Entry)(int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Task * task = reinterpret_cast<Task*>(m[5]);
    Entry * entry = reinterpret_cast<Entry*>(m[6]);
    Thread * thread = new (SYSTEM) Thread(conf, task, entry, m[7]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_tc_2(int * m){
    typedef int (Entry)(int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Task * task = reinterpret_cast<Task*>(m[5]);
    Entry * entry = reinterpret_cast<Entry*>(m[6]);
    Thread * thread = new (SYSTEM) Thread(conf, task, entry, m[7], m[8]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_tc_3(int * m){
    typedef int (Entry)(int, int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Task * task = reinterpret_cast<Task*>(m[5]);
    Entry * entry = reinterpret_cast<Entry*>(m[6]);
    Thread * thread = new (SYSTEM) Thread(conf, task, entry, m[7], m[8], m[9]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_constructor_tc_4(int * m){
    typedef int (Entry)(int, int, int, int);
    Thread::Configuration conf = *reinterpret_cast<Thread::Configuration*>(m[4]);
    Task * task = reinterpret_cast<Task*>(m[5]);
    Entry * entry = reinterpret_cast<Entry*>(m[6]);
    Thread * thread = new (SYSTEM) Thread(conf, task, entry, m[7], m[8], m[9], m[10]);
    m[3] = reinterpret_cast<int>(thread);
}

void Skeleton::thread_destructor(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    delete thread;
}


void Skeleton::thread_join(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    m[3] = thread->join();
}

void Skeleton::thread_exit(int * m){
    Thread::exit(m[4]);
}

void Skeleton::thread_yield(int * m){
    Thread::yield();
}

void Skeleton::thread_resume(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    thread->resume();
}

void Skeleton::thread_suspend(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    thread->suspend();
}

void Skeleton::thread_pass(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    thread->pass();
}

void Skeleton::thread_task(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    m[3] = reinterpret_cast<int>(thread->task());
}

void Skeleton::thread_set_priority(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    Thread::Priority p = *reinterpret_cast<Thread::Priority*>(m[4]);
    thread->priority(p);
}

void Skeleton::thread_get_priority(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    m[3] = reinterpret_cast<int>(&thread->priority());
}

void Skeleton::thread_state(int * m){
    Thread * thread = reinterpret_cast<Thread*>(m[2]);
    m[3] = reinterpret_cast<int>(&thread->state());
}


// SEGMENT

void Skeleton::segment_constructor_1(int * m){
    unsigned int bytes = m[4];
    Segment::Flags flag = m[5];
    Segment * segment = new (SYSTEM) Segment(bytes, flag);
    m[2] = reinterpret_cast<int>(segment);
}

void Skeleton::segment_constructor_2(int * m){
    Segment::Phy_Addr addr = *reinterpret_cast<Segment::Phy_Addr*>(m[4]);
    unsigned int bytes = m[5];
    Segment::Flags flag = m[6];
    Segment * segment = new (SYSTEM) Segment(addr, bytes, flag);
    m[2] = reinterpret_cast<int>(segment);
}

void Skeleton::segment_destructor(int * m){
    Segment * s = reinterpret_cast<Segment*>(m[2]);
    delete s;
}

void Skeleton::segment_phy_address(int * m){
    Segment * s = reinterpret_cast<Segment*>(m[2]);
    Segment::Phy_Addr phy = s->phy_address(); // TODO: variável é destruída no fim da função? (inconsistente)
    m[3] = reinterpret_cast<int>(&phy);
}

void Skeleton::segment_resize(int * m){
    Segment * s = reinterpret_cast<Segment*>(m[2]);
    int amount = m[4];
    int ret = s->resize(amount);
    m[3] = ret;
}

void Skeleton::segment_size(int * m){
    Segment * s = reinterpret_cast<Segment*>(m[2]);
    m[3] = s->size();
}


// TASK

void Skeleton::task_constructor(int * m){
    Segment cs = *reinterpret_cast<Segment*>(m[3]);
    Segment ds = *reinterpret_cast<Segment*>(m[4]);
    Task * task = new (SYSTEM) Task(cs, ds);
    m[2] = reinterpret_cast<int>(task);
}

void Skeleton::task_destructor(int * m){
    Task * task = reinterpret_cast<Task*>(m[2]);
    delete task;
    delete m;
}

void Skeleton::task_address_space(int * m){
    Task * task = reinterpret_cast<Task*>(m[2]);
    m[3] = reinterpret_cast<int>(task->address_space());
}

void Skeleton::task_code_segment(int * m){
    Task * task = reinterpret_cast<Task*>(m[2]);
    m[3] = reinterpret_cast<int>(task->code_segment());
}

//FIXME Talvez não de certo esse método, devido a vida util da variavel log_addr
void Skeleton::task_code(int * m){
    Task * task = reinterpret_cast<Task*>(m[2]);
    CPU_Common::Log_Addr log_addr = task->code();
    m[3] = reinterpret_cast<int>(&log_addr);
}

void Skeleton::task_data_segment(int * m){
    Task * task = reinterpret_cast<Task*>(m[2]);
    m[3] = reinterpret_cast<int>(task->data_segment());
}

//FIXME Talvez não de certo esse método, devido a vida util da variavel log_addr
void Skeleton::task_data(int * m){
    Task * task = reinterpret_cast<Task*>(m[2]);
    CPU_Common::Log_Addr log_addr = task->data();
    m[3] = reinterpret_cast<int>(&log_addr);
}

void Skeleton::task_self(int * m){
    m[3] = reinterpret_cast<int>(Task::self());
}


// OSTREAM

void Skeleton::ostream_constructor(int * m){
    OStream * ostream = new (SYSTEM) OStream();
    m[2] = reinterpret_cast<int>(ostream);
}

void Skeleton::ostream_destructor(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    delete ostream;
}

void Skeleton::ostream_char_ptr(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    const char * s = reinterpret_cast<const char*>(m[4]);
    *ostream << s;
}

void Skeleton::ostream_begl(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Begl begl;
    *ostream << begl;
}

void Skeleton::ostream_endl(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Endl endl;
    *ostream << endl;
}

void Skeleton::ostream_hex(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Hex hex;
    *ostream << hex;
}

void Skeleton::ostream_dec(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Dec dec;
    *ostream << dec;
}

void Skeleton::ostream_oct(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Oct oct;
    *ostream << oct;
}

void Skeleton::ostream_bin(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Bin bin;
    *ostream << bin;
}

void Skeleton::ostream_err(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    OStream::Err err;
    *ostream << err;
}

void Skeleton::ostream_uchar(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    char s = (char)(m[4]);
    *ostream << s;
}

void Skeleton::ostream_int(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    int s = m[4];
    *ostream << s;
}

void Skeleton::ostream_short(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    short s = (short)m[4];
    *ostream  << s;
}

void Skeleton::ostream_long(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    long s = (long)m[4];
    *ostream << s;
}

void Skeleton::ostream_uint(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    unsigned int s = (unsigned int)m[4];
    *ostream << s;
}

void Skeleton::ostream_ushort(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    unsigned short s = (unsigned short)m[4];
    *ostream << s;
}

void Skeleton::ostream_ulong(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    unsigned long s = (unsigned long)m[4];
    *ostream << s;
}

void Skeleton::ostream_llint(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    long long int s = (long long int)m[4];
    *ostream << s;
}

void Skeleton::ostream_ullint(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    unsigned long long int s = (unsigned long long int)m[4];
    *ostream << s;
}

void Skeleton::ostream_void_ptr(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    int i = m[4];
    void * s = reinterpret_cast<void*>(i);
    *ostream << s;
}

void Skeleton::ostream_float(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    int i = m[4];
    float s = *reinterpret_cast<float*>(i);
    *ostream << s;
}

void Skeleton::ostream_char(int * m){
    OStream * ostream = reinterpret_cast<OStream*>(m[2]);
    char s = (char)(m[4]);
    *ostream << s;
}

__END_SYS
