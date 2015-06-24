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
    Stub() {}
    template<typename T1>
    Stub(const T1 & a1): Adapter<Component>(a1) {}
    template<typename T1, typename T2>
    Stub(const T1 & a1, const T2 & a2): Adapter<Component>(a1, a2) {}
    template<typename T1, typename T2, typename T3>
    Stub(const T1 & a1, const T2 & a2, const T3 & a3): Adapter<Component>(a1, a2, a3) {}
    template<typename T1, typename T2, typename T3, typename T4>
    Stub(const T1 & a1, const T2 & a2, const T3 & a3, const T4 & a4): Adapter<Component>(a1, a2, a3, a4) {}

    ~Stub() {}
};

template<typename Component>
class Stub<Component, true>: public Proxy<Component>
{
public:
    Stub() {}
    template<typename T1>
    Stub(const T1 & a1): Proxy<Component>(a1) {}
    template<typename T1, typename T2>
    Stub(const T1 & a1, const T2 & a2): Proxy<Component>(a1, a2) {}
    template<typename T1, typename T2, typename T3>
    Stub(const T1 & a1, const T2 & a2, const T3 & a3): Proxy<Component>(a1, a2, a3) {}
    template<typename T1, typename T2, typename T3, typename T4>
    Stub(const T1 & a1, const T2 & a2, const T3 & a3, const T4 & a4): Proxy<Component>(a1, a2, a3, a4) {}

    ~Stub() {}
};

__END_SYS

#endif
