#ifndef __app_types_h
#define __app_types_h

__BEGIN_API

namespace Class {
	enum { //ADDRESS_SPACE, 
		   //ALARM, 
		   //ALARM_HANDLER,
		   CONDITION, 
		   //CONDITION_HANDLER,
		   MUTEX, 
		   //MUTEX_HANDLER,
		   //SEGMENT,
		   SEMAPHORE,
		   //SEMAPHORE_HANDLER,
		   TASK
		   //THREAD,
		   //THREAD_HANDLER 
		   };
}

namespace Method {

	//namespace Address_Space {
	//	enum { CONSTRUCTOR, DESTRUCTOR, ATTACH_1, ATTACH_2, DETACH, PHYSICAL };
	//}
	
	//namespace Alarm {
	//	enum { CONSTRUCTOR, DESTRUCTOR, FREQUENCY, DELAY };
	//}
	
	namespace Condition {
		enum { CONSTRUCTOR, DESTRUCTOR, WAIT, SIGNAL, BROADCAST };
	}
	
	//namespace Handler {
	//	enum { };
	//}
	
	namespace Mutex {
		enum { CONSTRUCTOR, DESTRUCTOR, LOCK, UNLOCK };
	}
	
	//namespace Mutex_Handler {
	//	enum { CONSTRUCTOR, DESTRUCTOR, OPERATOR }; 
	//}
		
	namespace Semaphore {
		enum { CONSTRUCTOR, DESTRUCTOR, P, V };
	}
	
	namespace Task {
		enum { CONSTRUCTOR, DESTRUCTOR, ADDRESS_SPACE, CODE_SEGMENT, CODE, DATA_SEGMENT, DATA, SELF };
	}

}

namespace API {
	typedef unsigned long Log_Addr;
}

__END_API

#endif