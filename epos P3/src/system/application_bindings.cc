// EPOS Application Binding

#include <stub/thread.h>
#include <application.h>
#include <cpu.h>


// Global objects
__BEGIN_SYS
OStream kerr;
__END_SYS


// Bindings
extern "C" {
    void _panic() { EPOS::APPLICATION::Thread::exit(-1); }
    void _exit(int s) { EPOS::APPLICATION::Thread::exit(s); }
}

__USING_SYS
extern "C" {
    void _print(const char *) {
//        int object_id = reinterpret_cast<int>(&kout);
//        int text = reinterpret_cast<int>(s);
//        int * message = new int[4] {8,20, object_id, text};
//        ASM("int $50" : : "a"(message));
//        delete message;
    }
}

