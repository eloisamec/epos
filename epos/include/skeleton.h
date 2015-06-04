#ifndef __skeleton_h
#define __skeleton_h

__BEGIN_SYS

#include <message.h>
#include <system/config.h>

class Skeleton {

public:
	static void call(Message *);
	
private:
	static void semaphore_constructor(Message *);
	static void semaphore_destrutor(Message *);
	static void semaphore_p(Message *);
	static void semaphore_v(Message *);
};

__END_SYS
#endif