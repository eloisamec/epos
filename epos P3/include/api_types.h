#ifndef __api_types_h
#define __api_types_h

#include <system/config.h>
#include <stub/stub.h>
#include <stub/message.h>
#include <stub/skeleton.h>
#include <architecture/ia32/mmu.h>
#include <utility/handler.h>
#include <rtc.h>
#include <tsc.h>
#include <thread.h>

__BEGIN_APPLICATION

// Definições de ID's das classes de stubs

namespace Class {
    enum { ADDRESS_SPACE     = 0,
           ALARM             = 1,
           FUNCTION_HANDLER  = 2,
           DELAY             = 3,
           CONDITION         = 4,
           CONDITION_HANDLER = 5,
           MUTEX             = 6,
           MUTEX_HANDLER     = 7,
           OSTREAM           = 8,
           SEGMENT           = 9,
           SEMAPHORE         = 10,
           SEMAPHORE_HANDLER = 11,
           TASK              = 12,
           THREAD            = 13,
           THREAD_HANDLER    = 14
         };
}

// Definições de ID's dos métodos de stubs

namespace Method {
namespace Address_Space { enum { CONSTRUCTOR_1, CONSTRUCTOR_2, DESTRUCTOR, ATTACH_1, ATTACH_2, SIZE, DETACH, PHYSICAL, PD }; }
namespace Alarm         { enum { CONSTRUCTOR, DESTRUCTOR, FREQUENCY, DELAY }; }
namespace Condition     { enum { CONSTRUCTOR, DESTRUCTOR, WAIT, _SIGNAL, BROADCAST }; }
namespace Delay         { enum { CONSTRUCTOR }; }
namespace Handler       { enum { CONSTRUCTOR, DESTRUCTOR, CALL }; }
namespace Mutex         { enum { CONSTRUCTOR, DESTRUCTOR, LOCK, UNLOCK}; }
namespace OStream       { enum {
    CONSTRUCTOR, DESTRUCTOR, BEGL, ENDL, HEX, DEC, OCT, BIN, ERR, CHAR, UCHAR, INT, SHORT, LONG, UINT, USHORT, ULONG, LLINT,
    ULLINT, VOID_PTR, CHAR_PTR, FLOAT};
}
namespace Segment       { enum { CONSTRUCTOR_1, CONSTRUCTOR_2, DESTRUCTOR, SIZE, PHY_ADDRESS, RESIZE }; }
namespace Semaphore     { enum { CONSTRUCTOR, DESTRUCTOR, P, V}; }
namespace Task          { enum { CONSTRUCTOR, DESTRUCTOR, ADDRESS_SPACE, CODE_SEGMENT, CODE, DATA_SEGMENT, DATA, SELF }; }
namespace Thread        { enum {
    CONSTRUCTOR_0, CONSTRUCTOR_1, CONSTRUCTOR_2, CONSTRUCTOR_3, CONSTRUCTOR_4, CONSTRUCTOR_5, CONSTRUCTOR_6, CONSTRUCTOR_T_0,
    CONSTRUCTOR_T_1, CONSTRUCTOR_T_2, CONSTRUCTOR_T_3, CONSTRUCTOR_T_4, CONSTRUCTOR_T_5, CONSTRUCTOR_C_0, CONSTRUCTOR_C_1,
    CONSTRUCTOR_C_2, CONSTRUCTOR_C_3, CONSTRUCTOR_C_4, CONSTRUCTOR_C_5, CONSTRUCTOR_TC_0, CONSTRUCTOR_TC_1, CONSTRUCTOR_TC_2,
    CONSTRUCTOR_TC_3, CONSTRUCTOR_TC_4, DESTRUCTOR, STATE, GET_PRIORITY, SET_PRIORITY, TASK, JOIN, PASS, SUSPEND, RESUME,
    SELF, YIELD, EXIT=1638};
}
}

// Definições de tipos usados pela API

typedef EPOS::S::U::Handler Handler;
typedef Handler::Function Function;
typedef EPOS::S::U::Function_Handler Function_Handler;

typedef EPOS::S::RTC_Common::Microsecond Microsecond;
typedef EPOS::S::TSC_Common::Hertz Hertz;

typedef EPOS::S::CPU_Common::Phy_Addr Phy_Addr;
typedef EPOS::S::CPU_Common::Log_Addr Log_Addr;


static const unsigned int STACK_SIZE = EPOS::S::Traits<EPOS::S::Application>::STACK_SIZE;

typedef EPOS::S::Scheduling_Criteria::Priority Priority;

typedef EPOS::S::IA32_MMU::Page_Directory Page_Directory;
typedef EPOS::S::IA32_MMU::IA32_Flags Flags;
typedef EPOS::S::Thread::Configuration Configuration;

typedef EPOS::S::OStream::Begl Begl;
typedef EPOS::S::OStream::Endl Endl;
typedef EPOS::S::OStream::Hex Hex;
typedef EPOS::S::OStream::Dec Dec;
typedef EPOS::S::OStream::Oct Oct;
typedef EPOS::S::OStream::Bin Bin;
typedef EPOS::S::OStream::Err Err;

__END_APPLICATION

#endif
