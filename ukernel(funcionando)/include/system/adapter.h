// EPOS Component Framework - Scenario Adapter

#ifndef __adapter_h
#define __adapter_h

#include "scenario.h"

__BEGIN_SYS

template<typename Component>
class Adapter: public Component, public Scenario<Component>
{
    using Scenario<Component>::enter;
    using Scenario<Component>::leave;
    using Scenario<Component>::static_enter;
    using Scenario<Component>::static_leave;

public:
    typedef Component _Component;

public:
    Adapter() { static_leave(); }
    template<typename T1>
    Adapter(const T1 & a1): Component(a1) { static_leave(); }
    template<typename T1, typename T2>
    Adapter(const T1 & a1, const T2 & a2): Component(a1, a2) { static_leave(); }
    template<typename T1, typename T2, typename T3>
    Adapter(const T1 & a1, const T2 & a2, const T3 & a3): Component(a1, a2, a3) { static_leave(); }
    template<typename T1, typename T2, typename T3, typename T4>
    Adapter(const T1 & a1, const T2 & a2, const T3 & a3, const T4 & a4): Component(a1, a2, a3, a4) { static_leave(); }

    ~Adapter() { static_enter(); }

    void * operator new(size_t bytes) {
	static_enter();
	return Scenario<Component>::operator new(bytes);
    }

    void operator delete(void * adapter) {
	Scenario<Component>::operator delete(adapter);
	static_leave();
    }


    static const Adapter<Component> * self() { static_enter(); const Adapter<Component> * res = reinterpret_cast<const Adapter<Component> *>(Component::self()); return res; }

    // Process management
    void suspend() { enter(); Component::suspend(); leave(); }
    void resume() { enter(); Component::resume(); leave(); }
    int join() { enter(); int res = Component::join(); leave(); return res; }
    void pass() { enter(); Component::pass(); leave(); }
    static void yield() { static_enter(); Component::yield(); static_leave(); }
    static void exit(int status) { static_enter(); Component::exit(status); static_leave(); }

    Address_Space * address_space() { enter(); Address_Space * res = Component::address_space(); leave(); return res; }
    const Segment * code_segment() { enter(); const Segment * res = Component::code_segment(); leave(); return res; }
    const Segment * data_segment() { enter(); const Segment * res = Component::data_segment(); leave(); return res; }
    CPU::Log_Addr code() { enter(); CPU::Log_Addr res = Component::code(); leave(); return res; }
    CPU::Log_Addr data() { enter(); CPU::Log_Addr res = Component::data(); leave(); return res; }

    // Memory management
    CPU::Log_Addr attach(const Segment & seg) { enter(); CPU::Log_Addr res = Component::attach(seg); leave(); return res; }
    CPU::Log_Addr attach(const Segment & seg, CPU::Log_Addr addr) { enter(); CPU::Log_Addr res = Component::attach(seg, addr); leave(); return res; }
    void detach(const Segment & seg) { enter(); Component::detach(seg); leave(); }
    MMU::Directory * pd() { enter(); MMU::Directory * res = Component::pd(); leave(); return res; }

    unsigned int size() { enter(); unsigned int res = Component::size(); leave(); return res; }
    CPU::Phy_Addr phy_address() { enter(); CPU::Phy_Addr res = Component::phy_address(); leave(); return res; }
    int resize(int amount) { enter(); int res = Component::resize(amount); leave(); return res; }

    // Synchronization
    void lock() { enter(); Component::lock(); leave(); }
    void unlock() { enter(); Component::unlock(); leave(); }
    void p() { enter(); Component::p(); leave(); }
    void v() { enter(); Component::v(); leave(); }
    void wait() { enter(); Component::wait(); leave(); }
    void signal() { enter(); Component::signal(); leave(); }
    void broadcast() { enter(); Component::broadcast(); leave(); }

    // Timing
    static void delay(const RTC::Microsecond & time) { static_enter(); Component::delay(time); static_leave(); }
    void reset() { enter(); Component::reset(); leave(); }
    void start() { enter(); Component::start(); leave(); }
    void lap() { enter(); Component::lap(); leave(); }
    void stop() { enter(); Component::stop(); leave(); }
    int frequency() { enter(); int res = Component::frequency(); leave(); return res; }
    int ticks() { enter(); int res = Component::ticks(); leave(); return res; }
    int read() { enter(); int res = Component::read(); leave(); return res; }

     // Communication
     template<typename T1, typename T2, typename T3>
     int send(T1 & a1, T2 & a2, T3 & a3) {
	 enter();
	 int res = Component::send(a1, a2, a3);
	 leave();
	 return res;
     }
     template<typename T1, typename T2, typename T3>
     int receive(T1 & a1, T2 & a2, T3 & a3) {
	enter();
	int res = Component::receive(a1, a2, a3);
	leave();
	return res;
    }
};

__END_SYS

#endif
