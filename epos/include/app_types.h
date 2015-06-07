#ifndef __app_types_h
#define __app_types_h

#include <system/config.h>
#include <tsc.h>
#include <rtc.h>

__BEGIN_API

	typedef RTC::Microsecond Microsecond;
	typedef TSC::Hertz Hertz;
	typedef CPU::Phy_Addr Phy_Addr;
    typedef CPU::Log_Addr Log_Addr;
	typedef MMU::Flags Flags;
    typedef CPU::Phy_Addr Phy_Addr;
    typedef void (Function)();
	
namespace Class {
	enum { ADDRESS_SPACE, 
		   ALARM, 
		   CONDITION, 
		   DISPLAY,
		   HANDLER,
		   MUTEX, 
		   SEGMENT,
		   SEMAPHORE,
		   TASK,
		   THREAD };
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
	
	namespace Display {
		enum { CONSTRUCTOR, CLEAR, PUTC, PUTS, GEOMETRY, POSITION_1, POSITION_2 };
	}
	
	namespace Handler {
		enum { CONSTRUCTOR, DESTRUCTOR };
	}
	
	namespace Mutex {
		enum { CONSTRUCTOR, DESTRUCTOR, LOCK, UNLOCK };
	}
	
	namespace Segment {
		enum { CONSTRUCTOR_1, CONSTRUCTOR_2, DESTRUCTOR, SIZE, PHY_ADDRESS, RESIZE };
	}
	
	namespace Semaphore {
		enum { CONSTRUCTOR, DESTRUCTOR, P, V };
	}
	
	namespace Task {
		enum { CONSTRUCTOR, DESTRUCTOR, ADDRESS_SPACE, CODE_SEGMENT, CODE, DATA_SEGMENT, DATA, SELF };
	}

	namespace Thread {
		enum { CONSTRUCTOR_1, CONSTRUCTOR_2, CONSTRUCTOR_3, CONSTRUCTOR_4, DESTRUCTOR, STATE, PRIORITY_1, PRIORITY_2, TASK, JOIN, PASS, SUSPEND, RESUME, SELF, YIELD, EXIT };
	}
}
	
__END_API

#endif
