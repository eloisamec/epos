// EPOS Component Framework - Component Stub

#ifndef __stub_h
#define __stub_h

#include "adapter.h"
#include "proxy.h"

__BEGIN_SYS

template<typename Component, bool remote>
class Stub: public Adapter<Component>
{
public:
    template< typename ... Ts >
    Stub( const Ts & ... ts ) : Adapter<Component>(ts...) {}

    ~Stub() {}
};

template<typename Component>
class Stub<Component, true>: public Proxy<Component>
{
public:
    template< typename ... Ts >
    Stub( const Ts & ... ts ) : Proxy<Component>( ts... ) {}

    ~Stub() {}
};

__END_SYS

#endif
