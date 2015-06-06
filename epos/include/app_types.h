#ifndef __app_types_h
#define __app_types_h

__BEGIN_API

namespace Class {
	enum { ADDRESS_SPACE, 
		   ALARM, 
		   CONDITION, 
		   CONDITION_HANDLER,
		   DISPLAY,
		   HANDLER,
		   MUTEX, 
		   MUTEX_HANDLER,
		   SEGMENT,
		   SEMAPHORE,
		   SEMAPHORE_HANDLER,
		   TASK,
		   THREAD,
		   THREAD_HANDLER };
}

namespace Method {

	namespace Address_Space {
		enum { CONSTRUCTOR_1, CONSTRUCTOR_2, DESTRUCTOR, ATTACH_1, ATTACH_2, DETACH, PHYSICAL };
	}
	
	namespace Alarm {
		enum { CONSTRUCTOR, DESTRUCTOR, FREQUENCY, DELAY };
	}
	
	namespace Condition {
		enum { CONSTRUCTOR, DESTRUCTOR, WAIT, SIGNAL, BROADCAST };
	}
	
	namespace Condition_Handler {
		enum { CONSTRUCTOR, DESTRUCTOR  };
	}
	
	namespace Display {
		enum { CONSTRUCTOR, DESTRUCTOR  };
	}
	
	namespace Handler {
		enum { };
	}
	
	namespace Mutex {
		enum { CONSTRUCTOR, DESTRUCTOR, LOCK, UNLOCK };
	}
	
	namespace Mutex_Handler {
		enum { CONSTRUCTOR, DESTRUCTOR, OPERATOR }; 
	}
		
	namespace Segment {
		enum { CONSTRUCTOR, DESTRUCTOR };
	}
	
	namespace Semaphore {
		enum { CONSTRUCTOR, DESTRUCTOR, P, V };
	}
	
	namespace Semaphore_Handler {
		enum { CONSTRUCTOR, DESTRUCTOR, OPERATOR };
	}
	
	namespace Task {
		enum { CONSTRUCTOR, DESTRUCTOR, ADDRESS_SPACE, CODE_SEGMENT, CODE, DATA_SEGMENT, DATA, SELF };
	}

	namespace Thread {
		enum { CONSTRUCTOR, DESTRUCTOR };
	}
	
	namespace Thread_Handler {
		enum { CONSTRUCTOR, DESTRUCTOR };
	}
}

__END_API

#endif