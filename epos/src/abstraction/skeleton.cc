#include <stub/skeleton.h>
#include <table_class_method.h>
#include <semaphore.h>
#include <mutex.h>
#include <task.h>
#include <address_space.h>
#include <segment.h>
#include <architecture/ia32/mmu.h>

__BEGIN_SYS

	void Skeleton::call(Message * m){
		switch(m->class_id()){
		case Class::SEMAPHORE:
			switch(m->method_id()){
				case Method::Semaphore::CONSTRUCTOR: semaphore_constructor(m); break;
				case Method::Semaphore::DESTRUCTOR: semaphore_destrutor(m); break;
				case Method::Semaphore::P: semaphore_p(m); break;
				case Method::Semaphore::V: semaphore_v(m); break;
			}
			break;
		case Class::MUTEX:
			switch(m->method_id()){
				case Method::Mutex::CONSTRUCTOR: mutex_constructor(m); break;
				case Method::Mutex::DESTRUCTOR: mutex_destrutor(m); break;
				case Method::Mutex::LOCK: mutex_lock(m); break;
				case Method::Mutex::UNLOCK: mutex_unlock(m); break;
			}
			break;
		case Class::TASK:
			switch(m->method_id()) {
				case Method::Task::CONSTRUCTOR: task_constructor(m); break;
				case Method::Task::DESTRUCTOR: task_destrutor(m); break;
				case Method::Task::CODE_SEGMENT: task_code_segment(m); break;
				case Method::Task::DATA_SEGMENT: task_data_segment(m); break;
				case Method::Task::DATA: task_data(m); break;
				case Method::Task::CODE: task_code(m); break;
				case Method::Task::ADDRESS_SPACE: task_address_space(m); break;
				case Method::Task::SELF: task_self(m); break;
			}
			break;
		}
	}
	
	// Semaphore
	void Skeleton::semaphore_constructor(Message * m){
		int v = reinterpret_cast<int>(m->param1());
		Semaphore * sem = new (SYSTEM) Semaphore(v);
		m->return_value(reinterpret_cast<void *>(&sem));
	}

	void Skeleton::semaphore_destrutor(Message * m){
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

	// Mutex
	void Skeleton::mutex_constructor(Message * m) {
		Mutex * mutex = new (SYSTEM) Mutex();
		m->return_value(reinterpret_cast<void *>(&mutex));
	}
	
	void Skeleton::mutex_destrutor(Message * m) {
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
	
	// Task
	void Skeleton::task_constructor(Message * m) {
		Segment p1 = *reinterpret_cast<Segment*>(m->param1());
		Segment p2 = *reinterpret_cast<Segment*>(m->param2());
		Task * task = new (SYSTEM) Task(p1, p2);
		m-> return_value(reinterpret_cast<void *>(&task));
		
	}
	
	void Skeleton::task_destrutor(Message * m) {
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
		m->return_value(reinterpret_cast<void *> (cs));
	}
	
	void Skeleton::task_code(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		CPU::Log_Addr code = *reinterpret_cast<CPU::Log_Addr *>(task->code());
		m->return_value(reinterpret_cast<void *> (code));
	}
	
	void Skeleton::task_data_segment(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		Segment * ds = const_cast<Segment *>(task->data_segment());
		m->return_value(reinterpret_cast<void *> (ds));
	}
	
	void Skeleton::task_data(Message * m) {
		Task * task = reinterpret_cast<Task*>(m->object_id());
		API::Log_Addr data = *reinterpret_cast<API::Log_Addr *>(task->data());
		m->return_value(reinterpret_cast<void *> (data));
	}
	
	void Skeleton::task_self(Message * m) {
		Task * task = Task::self();
		m->return_value(reinterpret_cast<void *> (task));
	}
	
__END_SYS