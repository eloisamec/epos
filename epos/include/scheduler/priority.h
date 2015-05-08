#ifndef __scheduler_h
#define __scheduler_h

__BEGIN_SYS

class Priority : public Criterion{

public:
	enum {
		MAIN   = 0,
        HIGH   = 1,
        NORMAL = (unsigned(1) << (sizeof(int) * 8 - 1)) - 3,
        LOW    = (unsigned(1) << (sizeof(int) * 8 - 1)) - 2,
        IDLE   = (unsigned(1) << (sizeof(int) * 8 - 1)) - 1
	};

	static const bool timed = false;
    static const bool preemptive = true;

public:
    Priority(int p = NORMAL): _priority(p) {}

    operator const volatile int() const volatile { return _priority; }

protected:
	volatile int _priority;
};

__END_SYS

#endif