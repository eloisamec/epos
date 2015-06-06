// EPOS Component Framework - Component Handle

#ifndef __handle_h
#define __handle_h

#include "stub.h"

__BEGIN_SYS

template<typename Component>
class Handle;


template<typename Component>
class Handled: public Handle<Component>
{
public:
    Handled(): Handle<Component>(Handle<Component>::HANDLED) {
        db<Framework>(TRC) << "Handled() => [s= " << Handle<Component>::_stub << "]" << endl;
        db<Framework>(WRN) << "sizeof(Component) = " << sizeof(Component) << endl;
        db<Framework>(WRN) << "sizeof(Stub) = " << sizeof(typename Handle<Component>::_Stub) << endl;
    }

    void * operator new(size_t s, void * c) {
        db<Framework>(TRC) << "Handled::new(c=" << c << ")" << endl;
        return new Handle<Component>(reinterpret_cast<typename Handle<Component>::_Stub *>(c)); }
};


template<typename Component>
class Handle
{
    template<typename> friend class Handle;
    template<typename> friend class Handled;

protected:
    typedef Stub<Component, Traits<System>::mode == Traits<Build>::KERNEL> _Stub;

protected:
    enum Private_Handle{ HANDLED };
    Handle(const Private_Handle & h) {}
    Handle(_Stub * s) { _stub = s; }

public:
    Handle() {_stub = new _Stub;}

    template< typename ... Ts >
    Handle(const Ts& ... ts )
    { _stub = new _Stub( ts... ); }

    template< typename ... Ts >
    Handle(const Handle<Task> & t, const Ts & ... ts ) {
        _stub = new _Stub(*t._stub, ts...);
    }

    ~Handle() { if(_stub) delete _stub; }

    static Handle<Component> * self() { return new (_Stub::self()) Handled<Component>; }

    // Process management
    void suspend() { _stub->suspend(); }
    void resume() { _stub->resume(); }
    int join() { return _stub->join(); }
    int pass() { return _stub->pass(); }
    static void yield() { _Stub::yield(); }
    static void exit(int r = 0) { _Stub::exit(r); }

    Handle<Address_Space> * address_space() const { return new (_stub->address_space()) Handled<Address_Space>; }
    Handle<Segment> * code_segment() const { return new (_stub->code_segment()) Handled<Segment>; }
    Handle<Segment> * data_segment() const { return new (_stub->data_segment()) Handled<Segment>; }
    CPU::Log_Addr code() const { return _stub->code(); }
    CPU::Log_Addr data() const { return _stub->data(); }

    // Memory Management
    CPU::Log_Addr attach(const Handle<Segment> & seg) { return _stub->attach(*seg._stub); }
    CPU::Log_Addr attach(const Handle<Segment> & seg, CPU::Log_Addr addr) { return _stub->attach(*seg._stub, addr); }
    void detach(const Handle<Segment> & seg) { _stub->detach(*seg._stub); }

    unsigned int size() const { return _stub->size(); }
    CPU::Phy_Addr phy_address() const { return _stub->phy_address(); }
    int resize(int amount) { return _stub->resize(amount); }

    // Synchronization
    void lock() { _stub->lock(); }
    void unlock() { _stub->unlock(); }

    void p() { _stub->p(); }
    void v() { _stub->v(); }

    void wait() { _stub->wait(); }
    void signal() { _stub->signal(); }
    void broadcast() { _stub->broadcast(); }

    // Timing
    template<typename T>
    static void delay(T a) { _Stub::delay(a); }

    void reset() { _stub->reset(); }
    void start() { _stub->start(); }
    void lap() { _stub->lap(); }
    void stop() { _stub->stop(); }

    int frequency() { return _stub->frequency(); }
    int ticks() { return _stub->ticks(); }
    int read() { return _stub->read(); }

    // Communication
    template<typename T1, typename T2, typename T3>
    int send(T1 & a1, T2 & a2, T3 & a3) {
	return _stub->send(a1, a2, a3);
    }
    template<typename T1, typename T2, typename T3>
    int receive(T1 & a1, T2 & a2, T3 & a3) {
	return _stub->receive(a1, a2, a3);
    }

private:
    _Stub * _stub;
};

__END_SYS

#endif
