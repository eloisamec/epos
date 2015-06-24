// EPOS Component Framework - Execution Scenario

#ifndef __scenario_h
#define __scenario_h

#include "aspect.h"

__BEGIN_SYS

template<typename Component>
class Scenario: public Aspects<Component>
{
protected:
    Scenario() {}

public:
    ~Scenario() {}

    void * operator new(size_t bytes) {
        return ::operator new(bytes, SYSTEM);
    }

    void operator delete(void * ptr) {
        ::operator delete(ptr);
    }


//    static Adapter<Component> * get(const Id & id) {
//	return alloc(); // FIXME: real get must come here
//    }
//
//    static Adapter<Component> * share(const Id & id) {
//	return alloc(); // FIXME: real share must come here
//    }
//
//    static Adapter<Component> * share(Adapter<Component> * adapter) {
//	return adapter;
//    }

    void enter() {}

    void leave() {}

    static void static_enter() {}

    static void static_leave() {}
};

__END_SYS

#endif
