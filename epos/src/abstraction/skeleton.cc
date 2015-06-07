#include <stub/skeleton.h>
#include <address_space.h>
#include <alarm.h>
#include <app_types.h>
#include <condition.h>
#include <mutex.h>
#include <semaphore.h>
#include <task.h>
#include <display.h>
//#include <segment.h>
//#include <architecture/ia32/mmu.h>

__BEGIN_SYS

	void Skeleton::call(Message * m){
		switch(m->class_id()){
			case Class::ADDRESS_SPACE:
				switch(m->method_id()){
					case Method::Address_Space::CONSTRUCTOR_1: address_space_constructor_1(m); break;
					case Method::Address_Space::CONSTRUCTOR_2: address_space_constructor_2(m); break;
					case Method::Address_Space::DESTRUCTOR: address_space_destructor(m); break;
					case Method::Address_Space::ATTACH_1: address_space_attach_1(m); break;
					case Method::Address_Space::ATTACH_2: address_space_attach_2(m); break;
					case Method::Address_Space::DETACH: address_space_detach(m); break;
					case Method::Address_Space::PHYSICAL: address_space_physical(m); break;
				}
				break;
			case Class::ALARM:
				switch(m->method_id()){
					case Method::Alarm::CONSTRUCTOR: alarm_constructor(m); break;
					case Method::Alarm::DESTRUCTOR: alarm_destructor(m); break;
					case Method::Alarm::FREQUENCY: alarm_frequency(m); break;
					case Method::Alarm::DELAY: alarm_delay(m); break;
				}
				break;
			case Class::CONDITION:
				switch(m->method_id()){
					case Method::Condition::CONSTRUCTOR: condition_constructor(m); break;
					case Method::Condition::DESTRUCTOR: condition_destructor(m); break;
					case Method::Condition::WAIT: condition_wait(m); break;
					case Method::Condition::SIGNAL: condition_signal(m); break;
					case Method::Condition::BROADCAST: condition_broadcast(m); break;
				}
				break;
			case Class::DISPLAY:
				switch(m->method_id()){
					case Method::Display::CONSTRUCTOR: display_constructor(m); break;
					case Method::Display::CLEAR: display_clear(m); break;
					case Method::Display::PUTC: display_putc(m); break;
					case Method::Display::PUTS: display_puts(m); break;
					case Method::Display::GEOMETRY: display_geometry(m); break;
					case Method::Display::POSITION_1: display_position_1(m); break;
					case Method::Display::POSITION_2: display_position_2(m); break;
				}
				break;
			case Class::HANDLER:
				switch(m->method_id()){
					case Method::Handler::CONSTRUCTOR: handler_constructor(m); break;
					case Method::Handler::DESTRUCTOR: handler_destructor(m); break;
					case Method::Handler::OPERATOR: handler_operator(m); break;
				}
				break;
			case Class::MUTEX:
				switch(m->method_id()){
					case Method::Mutex::CONSTRUCTOR: mutex_constructor(m); break;
					case Method::Mutex::DESTRUCTOR: mutex_destructor(m); break;
					case Method::Mutex::LOCK: mutex_lock(m); break;
					case Method::Mutex::UNLOCK: mutex_unlock(m); break;
				}
				break;
			case Class::SEGMENT:
				switch(m->method_id()){
					case Method::Segment::CONSTRUCTOR_1: segment_constructor_1(m); break;
					case Method::Segment::CONSTRUCTOR_2: segment_constructor_2(m); break;
					case Method::Segment::DESTRUCTOR: segment_destructor(m); break;
					case Method::Segment::SIZE: segment_size(m); break;
					case Method::Segment::PHY_ADDRESS: segment_phy_address(m); break;
					case Method::Segment::RESIZE: segment_resize(m); break;
				}
				break;
			case Class::SEMAPHORE:
				switch(m->method_id()){
					case Method::Semaphore::CONSTRUCTOR: semaphore_constructor(m); break;
					case Method::Semaphore::DESTRUCTOR: semaphore_destructor(m); break;
					case Method::Semaphore::P: semaphore_p(m); break;
					case Method::Semaphore::V: semaphore_v(m); break;
				}
				break;
			case Class::TASK:
				switch(m->method_id()) {
					case Method::Task::CONSTRUCTOR: task_constructor(m); break;
					case Method::Task::DESTRUCTOR: task_destructor(m); break;
					case Method::Task::CODE_SEGMENT: task_code_segment(m); break;
					case Method::Task::DATA_SEGMENT: task_data_segment(m); break;
					case Method::Task::DATA: task_data(m); break;
					case Method::Task::CODE: task_code(m); break;
					case Method::Task::ADDRESS_SPACE: task_address_space(m); break;
					case Method::Task::SELF: task_self(m); break;
				}
				break;
			case Class::THREAD:
				switch(m->method_id()) {
					case Method::Thread::CONSTRUCTOR_1: thread_constructor_1(m); break;
					case Method::Thread::CONSTRUCTOR_2: thread_constructor_2(m); break;
					case Method::Thread::CONSTRUCTOR_3: thread_constructor_3(m); break;
					case Method::Thread::CONSTRUCTOR_4: thread_constructor_4(m); break;
					case Method::Thread::DESTRUCTOR: thread_destructor(m); break;
					case Method::Thread::STATE: thread_state(m); break;
					case Method::Thread::PRIORITY_1: thread_priority_1(m); break;
					case Method::Thread::PRIORITY_2: thread_priority_2(m); break;
					case Method::Thread::TASK: thread_task(m); break;
					case Method::Thread::JOIN: thread_join(m); break;
					case Method::Thread::PASS: thread_pass(m); break;
					case Method::Thread::SUSPEND: thread_suspend(m); break;
					case Method::Thread::RESUME: thread_resume(m); break;
					case Method::Thread::SELF: thread_self(m); break;
					case Method::Thread::YIELD: thread_yield(m); break;
					case Method::Thread::EXIT: thread_exit(m); break;
				}
				break;
		}
	}
	
	// Address Space
	void Skeleton::address_space_constructor_1(Message * m) {
		Address_Space * address_space = new (SYSTEM) Address_Space();
		m->return_value(reinterpret_cast<void *>(&address_space));
	}
	
	void Skeleton::address_space_constructor_2(Message * m) {
		MMU::Page_Directory pd = *reinterpret_cast<MMU::Page_Directory *>(m->param1());
		Address_Space * address_space = new (SYSTEM) Address_Space(&pd);
		m->return_value(reinterpret_cast<void *>(&address_space));
	}
	
	void Skeleton::address_space_destructor(Message * m) {
		Address_Space * address_space = reinterpret_cast<Address_Space *>(m->object_id());
		delete address_space;
	}
	
	void Skeleton::address_space_attach_1(Message * m) {
		Address_Space * address_space = reinterpret_cast<Address_Space*>(m->object_id());
		Segment p1 = *reinterpret_cast<Segment*>(m->param1());
		CPU_Common::Log_Addr la = address_space->attach(p1);
		m->return_value(reinterpret_cast<void *>(&la));
	}
	
	void Skeleton::address_space_attach_2(Message * m) {
		Address_Space * address_space = reinterpret_cast<Address_Space*>(m->object_id());
		Segment seg = *reinterpret_cast<Segment*>(m->param1());
		CPU_Common::Log_Addr log_addr = *reinterpret_cast<CPU_Common::Log_Addr *>(m->param2());
		CPU_Common::Log_Addr la = address_space->attach(seg, log_addr);
		m->return_value(reinterpret_cast<void *>(&la));
	}
	
	void Skeleton::address_space_detach(Message * m) {
		Address_Space * address_space = reinterpret_cast<Address_Space*>(m->object_id());
		Segment seg = *reinterpret_cast<Segment*>(m->param1());
		address_space->detach(seg);
	}
	
	void Skeleton::address_space_physical(Message * m) {
		CPU_Common::Log_Addr log_addr = *reinterpret_cast<CPU_Common::Log_Addr*>(m->param1());
		Address_Space * address_space = reinterpret_cast<Address_Space*>(m->object_id());
		address_space->physical(log_addr);
	}
	
	// Alarm
	void Skeleton::alarm_constructor(Message * m) {
		const RTC::Microsecond times = *reinterpret_cast<RTC::Microsecond*>(m->param1());
		Handler * handler = reinterpret_cast<Handler*>(m->param2());
		int time = *reinterpret_cast<int*>(m->param3());
		Alarm * alarm = new (SYSTEM) Alarm(times, handler, time);
		m->return_value(reinterpret_cast<void *>(&alarm));
	}
	
	void Skeleton::alarm_destructor(Message * m) {
		Alarm * alarm = reinterpret_cast<Alarm *>(m->object_id());
		delete alarm;
	}
	
	void Skeleton::alarm_frequency(Message * m) {
		Alarm * alarm = reinterpret_cast<Alarm*>(m->object_id());
		alarm->frequency();
	}
	
	void Skeleton::alarm_delay(Message * m) {
		Alarm * alarm = reinterpret_cast<Alarm*>(m->object_id());
		const RTC::Microsecond time = *reinterpret_cast<RTC::Microsecond*>(m->param1());
		alarm->delay(time);
	}

	// Condition
	void Skeleton::condition_constructor(Message * m) {
		Condition * condition = new (SYSTEM) Condition();
		m->return_value(reinterpret_cast<void *>(&condition));
	}
	
	void Skeleton::condition_destructor(Message * m) {
		Condition * condition = reinterpret_cast<Condition*>(m->object_id());
		delete condition;
	}
	
	void Skeleton::condition_wait(Message * m) {
		Condition * condition = reinterpret_cast<Condition*>(m->object_id());
		condition->wait();
	}
	
	void Skeleton::condition_signal(Message * m) {
		Condition * condition = reinterpret_cast<Condition*>(m->object_id());
		condition->signal();
	}
	
	void Skeleton::condition_broadcast(Message * m) {
		Condition * condition = reinterpret_cast<Condition*>(m->object_id());
		condition->broadcast();
	}
	
	// Display
	void Skeleton::display_constructor(Message * m) {
		Serial_Display();
	}
	
	void Skeleton::display_clear(Message * m) {
		Display::clear();
	}
	
	void Skeleton::display_putc(Message * m) {
		char c = *reinterpret_cast<char*>(m->param1());
		Display::putc(c);
	}
	
	void Skeleton::display_puts(Message * m) {
		const char s = *reinterpret_cast<char*>(m->param1());
		Display::puts(&s);
	}
	
	void Skeleton::display_geometry(Message * m) {
		int * lines = reinterpret_cast<int*>(m->param1());
		int * columns = reinterpret_cast<int*>(m->param2());
		Display::geometry(lines, columns);
	}
	
	void Skeleton::display_position_1(Message * m) {
		int * line = reinterpret_cast<int*>(m->param1());
		int * column = reinterpret_cast<int*>(m->param2());
		Display::geometry(line, column);
	}
	
	void Skeleton::display_position_2(Message * m) {
		int line = *reinterpret_cast<int*>(m->param1());
		int column = *reinterpret_cast<int*>(m->param2());
		Display::geometry(&line, &column);
	}
	
	// Handler
	void Skeleton::handler_constructor(Message * m) {
	
	}
	
	void Skeleton::handler_destructor(Message * m) {
	
	}
	
	void Skeleton::handler_operator(Message * m) {
	
	}
	
	// Mutex
	void Skeleton::mutex_constructor(Message * m) {
		Mutex * mutex = new (SYSTEM) Mutex();
		m->return_value(reinterpret_cast<void *>(&mutex));
	}
	
	void Skeleton::mutex_destructor(Message * m) {
		Mutex * mutex = reinterpret_cast<Mutex*>(m->object_id());
		delete mutex;
	}
	
	void Skeleton::mutex_lock(Message * m) {
		Mutex * mutex = reinterpret_cast<Mutex*>(m->object_id());
		mutex->lock();
	}
	
	void Skeleton::mutex_unlock(Message * m) {
		Mutex * mutex = reinterpret_cast<Mutex*>(m->object_id());
		mutex->unlock();
	}
	
	// Segment
	void Skeleton::segment_constructor_1(Message * m) {
	
	}
	
	void Skeleton::segment_constructor_2(Message * m) {
	
	}
	
	void Skeleton::segment_destructor(Message * m) {
	
	}
	
	void Skeleton::segment_size(Message * m) {
	
	}
	
	void Skeleton::segment_phy_address(Message * m) {
	
	}
	
	void Skeleton::segment_resize(Message * m) {
	
	}
	
	// Semaphore
	void Skeleton::semaphore_constructor(Message * m){
		int v = reinterpret_cast<int>(m->param1());
		Semaphore * sem = new (SYSTEM) Semaphore(v);
		m->return_value(reinterpret_cast<void *>(&sem));
	}

	void Skeleton::semaphore_destructor(Message * m){
		Semaphore * sem = reinterpret_cast<Semaphore*>(m->object_id());
		delete sem;
	}

	void Skeleton::semaphore_p(Message * m){
		Semaphore * sem = reinterpret_cast<Semaphore*>(m->object_id());
		sem->p();
	}

	void Skeleton::semaphore_v(Message * m){
		Semaphore * sem = reinterpret_cast<Semaphore*>(m->object_id());
		sem->v();
	}

	// Task
	void Skeleton::task_constructor(Message * m) {
		Segment p1 = *reinterpret_cast<Segment*>(m->param1());
		Segment p2 = *reinterpret_cast<Segment*>(m->param2());
		Task * task = new (SYSTEM) Task(p1, p2);
		m-> return_value(reinterpret_cast<void *>(&task));	
	}
	
	void Skeleton::task_destructor(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		delete task;
	}
	
	void Skeleton::task_address_space(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		Address_Space * address_space = task->address_space();
		m->return_value(reinterpret_cast<void *> (address_space));
	}
	
	void Skeleton::task_code_segment(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		Segment * cs = const_cast<Segment *>(task->code_segment());
		m->return_value(reinterpret_cast<void *>(cs));
	}
	
	void Skeleton::task_code(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		CPU_Common::Log_Addr code = task->code();
		m->return_value(reinterpret_cast<void *>(&code));
	}
	
	void Skeleton::task_data_segment(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		Segment * ds = const_cast<Segment *>(task->data_segment());
		m->return_value(reinterpret_cast<void *>(ds));
	}
	
	void Skeleton::task_data(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		CPU_Common::Log_Addr data = task->data();
		m->return_value(reinterpret_cast<void *>(&data));
	}
	
	void Skeleton::task_self(Message * m) {
		Task * task = Task::self();
		m->return_value(reinterpret_cast<void *>(task));
	}
	
	// Thread
	void Skeleton::thread_constructor_1(Message * m) {
	
	}
	
	void Skeleton::thread_constructor_2(Message * m) {
	
	}
	
	void Skeleton::thread_constructor_3(Message * m) {
	
	}
	
	void Skeleton::thread_constructor_4(Message * m) {
	
	}
	
	void Skeleton::thread_destructor(Message * m) {
	
	}
	
	void Skeleton::thread_state(Message * m) {
	
	}
	
	void Skeleton::thread_priority_1(Message * m) {
	
	}
	
	void Skeleton::thread_priority_2(Message * m) {
	
	}
	
	void Skeleton::thread_task(Message * m) {
	
	}
	
	void Skeleton::thread_join(Message * m) {
	
	}
	
	void Skeleton::thread_pass(Message * m) {
	
	}
	
	void Skeleton::thread_suspend(Message * m) {
	
	}
	
	void Skeleton::thread_resume(Message * m) {
	
	}
	
	void Skeleton::thread_self(Message * m) {
	
	}
	
	void Skeleton::thread_yield(Message * m) {
	
	}
	
	void Skeleton::thread_exit(Message * m) {
	
	}
	

__END_SYS
