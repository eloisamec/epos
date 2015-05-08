#ifndef __fifo_h
#define __fifo_h

#include <priority.h>
#include <tsc.h>

__BEGIN_SYS

class FCFS: public Priority {

public:
	enum {
		MAIN   = 0,
        NORMAL = 1,
		IDLE   = (unsigned(1) << (sizeof(int) * 8 - 1)) - 1
	};

	static const bool timed = false;
	static const bool preemptive = false;

public:
	FCFS(int p = NORMAL): Priority((p == IDLE) ? IDLE : TSC::time_stamp()) {}

};

__END_SYS
#endif