// EPOS Component Framework - Component Proxy

#ifndef __proxy_h
#define __proxy_h

#include "message.h"

__BEGIN_SYS

template<typename Component>
class Proxy;


template<typename Component>
class Proxied: public Proxy<Component>
{
public:
    Proxied(): Proxy<Component>(Proxy<Component>::PROXIED) {}

    void * operator new(size_t s, void * c) {
        db<Framework>(TRC) << "Proxied::new(c=" << c << ")" << endl;
        return new Proxy<Component>(reinterpret_cast<Adapter<Component> *>(c)); }
};


template<typename Component>
class Proxy
{
    template<typename> friend class Proxy;
    template<typename> friend class Proxied;

protected:
    typedef Adapter<Component> _Adapter;

    enum Private_Proxied{ PROXIED };
    Proxy(const Private_Proxied & p) {}

    Proxy(_Adapter * c) { _adapter = c; }

public:
    Proxy() { Message msg(Type<Component>::ID, 0); msg.invoke(Method::CREATE); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }
    template<typename T1>
    Proxy(const T1 & p1) { Message msg(Type<Component>::ID, 0); msg.out(p1); msg.invoke(Method::CREATE1); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }
    template<typename T1, typename T2>
    Proxy(const T1 & p1, const T2 & p2) { Message msg(Type<Component>::ID, 0); msg.out(p1, p2); msg.invoke(Method::CREATE2); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }
    template<typename T1, typename T2, typename T3>
    Proxy(const T1 & p1, const T2 & p2, const T3 & p3) { Message msg(Type<Component>::ID, 0); msg.out(p1, p2, p3); msg.invoke(Method::CREATE3); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }
    template<typename T1, typename T2, typename T3, typename T4>
    Proxy(const T1 & p1, const T2 & p2, const T3 & p3, const T4 & p4) { Message msg(Type<Component>::ID, 0); msg.out(p1, p2, p3, p4); msg.invoke(Method::CREATE4); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }

    Proxy(const Proxy<Task> & task, void (* entry)()) { Message msg(Type<Component>::ID, 0); msg.out(task._adapter, entry); msg.invoke(Method::CREATE6); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }

    Proxy(const Proxy<Segment> & cs, const Proxy<Segment> & ds) { Message msg(Type<Component>::ID, 0); msg.out(cs._adapter, ds._adapter); msg.invoke(Method::CREATE6); _adapter = reinterpret_cast<_Adapter *>(msg.id().unit()); }

    ~Proxy() { Message msg(Type<Component>::ID, 0); msg.invoke(Method::DESTROY); }

    static Proxy<Component> * self() { Message msg(Type<Component>::ID, 0); msg.invoke(Method::SELF); return new (reinterpret_cast<_Adapter *>(msg.id().unit())) Proxied<Component>; }

    // Process management
    void suspend() { Message msg(_adapter); msg.invoke(Method::THREAD_SUSPEND); }
    void resume() { Message msg(_adapter); msg.invoke(Method::THREAD_RESUME); }
    int join() { Message msg(_adapter); msg.invoke(Method::THREAD_JOIN); return msg.result(); }
    int pass() { Message msg(_adapter); msg.invoke(Method::THREAD_PASS); return msg.result(); }
    static int yield() { Message msg(Type<Component>::ID, 0); msg.invoke(Method::THREAD_YIELD); return msg.result(); }
    static void exit(int r) { Message msg(Type<Component>::ID, 0); msg.out(r); msg.invoke(Method::THREAD_EXIT); }

    Proxy<Address_Space> * address_space() { Message msg(_adapter); msg.invoke(Method::TASK_ADDRESS_SPACE); return new (reinterpret_cast<Adapter<Address_Space> *>(msg.result())) Proxied<Address_Space>; }
    Proxy<Segment> * code_segment() { Message msg(_adapter); msg.invoke(Method::TASK_CODE_SEGMENT); return new (reinterpret_cast<Adapter<Segment> *>(msg.result())) Proxied<Segment>; }
    Proxy<Segment> * data_segment() { Message msg(_adapter); msg.invoke(Method::TASK_DATA_SEGMENT); return new (reinterpret_cast<Adapter<Segment> *>(msg.result())) Proxied<Segment>; }
    CPU::Log_Addr code() { Message msg(_adapter); msg.invoke(Method::TASK_CODE); return msg.result(); }
    CPU::Log_Addr data() { Message msg(_adapter); msg.invoke(Method::TASK_DATA); return msg.result(); }

    // Memory management
    CPU::Log_Addr attach(const Proxy<Segment> & seg) { Message msg(_adapter); msg.out(seg._adapter); msg.invoke(Method::ADDRESS_SPACE_ATTACH1); return msg.result(); }
    CPU::Log_Addr attach(const Proxy<Segment> & seg, CPU::Log_Addr addr) { Message msg(_adapter); msg.out(seg._adapter, addr); msg.invoke(Method::ADDRESS_SPACE_ATTACH2); return msg.result(); }
    void detach(const Proxy<Segment> & seg) { Message msg(_adapter); msg.out(seg._adapter); msg.invoke(Method::ADDRESS_SPACE_DETACH);}

    unsigned int size() { Message msg(_adapter); msg.invoke(Method::SEGMENT_SIZE); return msg.result(); }
    CPU::Phy_Addr phy_address() { Message msg(_adapter); msg.invoke(Method::SEGMENT_PHY_ADDRESS); return msg.result(); }
    int resize(int amount) { Message msg(_adapter); msg.invoke(Method::SEGMENT_RESIZE); return msg.result(); }

    // Synchronization
    void lock() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_LOCK); }
    void unlock() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_UNLOCK); }

    void p() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_P); }
    void v() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_V); }

    void wait() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_WAIT); }
    void signal() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_SIGNAL); }
    void broadcast() { Message msg(_adapter); msg.invoke(Method::SYNCHRONIZER_BROADCAST); }

    // Timing
    template<typename T>
    static void delay(T t) { Message msg(Type<Component>::ID, 0); msg.out(t); msg.invoke(Method::ALARM_DELAY); }

    // Communication
    template<typename T1, typename T2, typename T3>
    int send(T1 a1, T2 a2, T3 a3) { Message msg(_adapter); msg.invoke(Method::SELF, a1, a2, a3); return msg.result(); }
    template<typename T1, typename T2, typename T3>
    int receive(T1 a1, T2 a2, T3 a3) { Message msg(_adapter); msg.invoke(Method::SELF, a1, a2, a3); return msg.result(); }

private:
    Adapter<Component> * _adapter;
};



__END_SYS

#endif
