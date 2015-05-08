#ifndef __roundrobin_h
#define __roundrobin_h

#include <priority.h>

__BEGIN_SYS

class RoundRobin : public Priority {

public:
	enum {
		MAIN   = 0,
        NORMAL = 1,
        IDLE   = (unsigned(1) << (sizeof(int) * 8 - 1)) - 1
	};

    static const bool timed = true;
    static const bool preemptive = true;

public:
    RoundRobin(int p = NORMAL): Priority(p) {}
};

__END_SYS
#endif