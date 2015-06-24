// EPOS System Scaffold and System Abstraction Implementation

#include <utility/ostream.h>
#include <utility/heap.h>
#include <machine.h>
#include <display.h>
#include <system.h>
#include <alarm.h>
#include <thread.h>
#include <system/agent.h>

__USING_SYS;

extern "C" {
    void _panic() {
        Machine::panic();
    }

    void _exit(int s) {
        Thread::exit(s);
    }

    void _exec(Message * msg) {
        if(msg->id().type() != UTILITY_ID)
            db<Framework>(TRC) << ":=>(" << *msg << ")" << endl;

        switch(msg->id().type()) {
        case THREAD_ID: Agent<Thread>::act(msg); break;
        case TASK_ID: Agent<Task>::act(msg); break;
        case ADDRESS_SPACE_ID: Agent<Address_Space>::act(msg); break;
        case SEGMENT_ID: Agent<Segment>::act(msg); break;
        case UTILITY_ID: Agent<Utility>::act(msg); break;
        case ALARM_ID: Agent<Alarm>::act(msg); break;
        default: msg->reply(Result(-1));
        }

        if(msg->id().type() != UTILITY_ID)
            db<Framework>(TRC) << "   (" << *msg << ") <=:" << endl;
    }

    void _print(const char * s) {
        Display::puts(s);
    }

    // LIBC Heritage
    void __cxa_pure_virtual() {
        db<void>(ERR) << "Pure Virtual method called!" << endl;
    }
}
