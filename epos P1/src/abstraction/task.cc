#include <system.h>
#include <task.h>

__BEGIN_SYS

Task * Task::_master;
Simple_List<Thread> Task::_threads;

Task::Task() { }

Task::Task(const Segment & cs, const Segment & ds) {
   _address_space = new (SYSTEM) Address_Space (MMU::current());
   _code_segment = const_cast<Segment *>(&cs);
   _data_segment = const_cast<Segment *>(&ds);
   _code = CPU::Phy_Addr(Memory_Map<Machine>::APP_CODE);
   _data = CPU::Phy_Addr(Memory_Map<Machine>::APP_DATA);
}

Task::~Task() {
   delete _address_space;
   delete _code_segment;
   delete _data_segment;

   while(!_threads.empty()) {
       Thread * t = _threads.remove()->object();
       delete t;
   }
}

Task * Task::self() {
       return Thread::self()->_task;
}

void Task::insert(Thread * t) {

   kout << "Task::insert(Thread * t): " << _threads.size() << " == 0" << endl;

   _threads.insert(&t->_link_task);
   t->_task = this;

   kout << "Task::insert(Thread * t): " << _threads.size() << " == 1" << endl;

}

void Task::remove(Thread * t) {
   
   _threads.remove(&t->_link_task);
   
}

Address_Space * Task::address_space() const {
   return _address_space;
}

Segment * Task::code_segment() const {
   return _code_segment;
}

Segment * Task::data_segment() const {
   return _data_segment;
}

CPU::Phy_Addr Task::code() const {
   return _code;
}

CPU::Phy_Addr Task::data() const {
   return _data;
}

__END_SYS