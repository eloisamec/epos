// EPOS Component Framework - Proxy x Agent Message

#ifndef __message_h
#define __message_h

#include "id.h"

extern "C" { int _syscall(void *); }

__BEGIN_SYS

class Method {
public:
    enum {
        CREATE,
        CREATE1,
        CREATE2,
        CREATE3,
        CREATE4,
        CREATE5,
        CREATE6,
        CREATE7,
        CREATE8,
        DESTROY,
        SELF,
        COMPONENT = 0x10,
        THREAD_SUSPEND = COMPONENT,
        THREAD_RESUME,
        THREAD_JOIN,
        THREAD_PASS,
        THREAD_YIELD,
        THREAD_EXIT,
        THREAD_WAIT_NEXT,
        TASK_ADDRESS_SPACE = COMPONENT,
        TASK_CODE_SEGMENT,
        TASK_DATA_SEGMENT,
        TASK_CODE,
        TASK_DATA,
        ADDRESS_SPACE_ATTACH1 = COMPONENT,
        ADDRESS_SPACE_ATTACH2,
        ADDRESS_SPACE_DETACH,
        ADDRESS_PHYSICAL,
        SEGMENT_SIZE = COMPONENT,
        SEGMENT_PHY_ADDRESS,
        SEGMENT_RESIZE,
        SYNCHRONIZER_LOCK = COMPONENT,
        SYNCHRONIZER_UNLOCK,
        SYNCHRONIZER_P,
        SYNCHRONIZER_V,
        SYNCHRONIZER_WAIT,
        SYNCHRONIZER_SIGNAL,
        SYNCHRONIZER_BROADCAST,
        ALARM_DELAY = COMPONENT,
        PRINT = COMPONENT,
        UNDEFINED = -1
    };

public:
    Method(int m = UNDEFINED) : _method(m) {}
    template <typename T>
    Method(T m) : _method(static_cast<int>(m)) {}
    template <typename T>
    Method(T * m) : _method(reinterpret_cast<int>(m)) {}

    operator int() const { return _method; }
    template <typename T>
    operator T () const { return reinterpret_cast<T>(_method); }


    friend Debug & operator << (Debug & db, const Method & m) { db << m._method; return db; }

private:
    int _method;
};

class Result: public Method
{
public:
    Result(int r = UNDEFINED) : Method(r) {}
    template <typename T>
    Result(T m) : Method(m) {}
    template <typename T>
    Result(T * m) : Method(m) {}
};

class Message
{
public:
    Message(const Id & id): _id(id) {}
    Message(const Id::Type_Id & t, const Id::Unit_Id & u): _id(Id(t, u)) {}
    template <typename Adapter>
    Message(const Adapter * a): _id(Id(Type<typename Adapter::_Component>::ID, reinterpret_cast<Id::Unit_Id>(a))) {}

    const Id & id() const { return _id; }
    void id(const Id & id) { _id = id; }
    template <typename Adapter>
    void id(const Adapter * a) { _id = Id(Type<typename Adapter::_Component>::ID, reinterpret_cast<Id::Unit_Id>(a)); }

    const Method & method() const { return _method; }
    void method(const Method & m) { _method = m; }

    void invoke(const Method & m) { _method = m; act(); }
    int result() { return _method; }

    void reply(const Result & r) { _method = r; }
    template <typename T>
    void reply(const T & r) { _method = reinterpret_cast<int>(r); }

    template<typename T1>
    void out(const T1 & v1) {
        *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0])) = v1;
    }

    template<typename T1, typename T2>
    void out(const T1 & v1, const T2 & v2) {
        *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0])) = v1;
        *static_cast<T2 *>(reinterpret_cast<void *>(&_parms[sizeof(T1)])) = v2;
    }

    template<typename T1, typename T2, typename T3>
    void out(const T1 & v1, const T2 & v2, const T3 & v3) {
        *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0])) = v1;
        *static_cast<T2 *>(reinterpret_cast<void *>(&_parms[sizeof(T1)])) = v2;
        *static_cast<T3 *>(reinterpret_cast<void *>(&_parms[sizeof(T1) + sizeof(T2)])) = v3;
    }

    template<typename T1, typename T2, typename T3, typename T4>
    void out(const T1 & v1, const T2 & v2, const T3 & v3, const T4 & v4) {
        *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0])) = v1;
        *static_cast<T2 *>(reinterpret_cast<void *>(&_parms[sizeof(T1)])) = v2;
        *static_cast<T3 *>(reinterpret_cast<void *>(&_parms[sizeof(T1) + sizeof(T2)])) = v3;
        *static_cast<T4 *>(reinterpret_cast<void *>(&_parms[sizeof(T1) + sizeof(T2) + sizeof(T3)])) = v4;
    }


    template<typename T1>
    void in(T1 & v1) {
        v1 = *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0]));
    }

    template<typename T1, typename T2>
    void in(T1 & v1, T2 & v2) {
        v1 = *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0]));
        v2 = *static_cast<T2 *>(reinterpret_cast<void *>(&_parms[sizeof(T1)]));
    }

    template<typename T1, typename T2, typename T3>
    void in(T1 & v1, T2 & v2, T3 & v3) {
        v1 = *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0]));
        v2 = *static_cast<T2 *>(reinterpret_cast<void *>(&_parms[sizeof(T1)]));
        v3 = *static_cast<T3 *>(reinterpret_cast<void *>(&_parms[sizeof(T1) + sizeof(T2)]));
    }

    template<typename T1, typename T2, typename T3, typename T4>
    void in(T1 & v1, T2 & v2, T3 & v3, T4 & v4) {
        v1 = *static_cast<T1 *>(reinterpret_cast<void *>(&_parms[0]));
        v2 = *static_cast<T2 *>(reinterpret_cast<void *>(&_parms[sizeof(T1)]));
        v3 = *static_cast<T3 *>(reinterpret_cast<void *>(&_parms[sizeof(T1) + sizeof(T2)]));
        v4 = *static_cast<T4 *>(reinterpret_cast<void *>(&_parms[sizeof(T1) + sizeof(T2) + sizeof(T3)]));
    }


    friend Debug & operator << (Debug & db, const Message & m) {
          db << "{id=" << m._id << ",m=" << static_cast<void *>(m._method)
             << ",p={" << reinterpret_cast<void *>(*static_cast<const int *>(reinterpret_cast<const void *>(&m._parms[0]))) << ","
             << reinterpret_cast<void *>(*static_cast<const int *>(reinterpret_cast<const void *>(&m._parms[4]))) << ","
             << reinterpret_cast<void *>(*static_cast<const int *>(reinterpret_cast<const void *>(&m._parms[8]))) << "}}";
          return db;
      }


private:
    int act() { return _syscall(this); }

private:
    Id _id;
    Method _method;
    char _parms[20];
};

__END_SYS

#endif
