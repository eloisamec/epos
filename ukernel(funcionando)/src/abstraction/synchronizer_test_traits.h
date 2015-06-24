#ifndef __traits_h
#define __traits_h

#include <system/config.h>

__BEGIN_SYS

// Global Configuration
template <typename T>
struct Traits
{
    static const bool enabled = true;
    static const bool debugged = true;
};

template <> struct Traits<Build>
{
    enum {LIBRARY, BUILTIN, KERNEL};
    static const unsigned int MODE = LIBRARY;

    enum {IA32};
    static const unsigned int ARCH = IA32;

    enum {PC};
    static const unsigned int MACH = PC;
};


// Utilities
template <> struct Traits<Debug>
{
    static const bool error   = true;
    static const bool warning = true;
    static const bool info    = false;
    static const bool trace   = false;
};

template <> struct Traits<Lists>: public Traits<void>
{
    static const bool debugged = false;
};

template <> struct Traits<Spin>: public Traits<void>
{
    static const bool debugged = false;
};

template <> struct Traits<Heap>: public Traits<void>
{
};


// System Parts (mostly to fine control debbugin)
template <> struct Traits<Boot>: public Traits<void>
{
};

template <> struct Traits<Setup>: public Traits<void>
{
};

template <> struct Traits<Init>: public Traits<void>
{
};


// Common Mediators
template <> struct Traits<Serial_Display>: public Traits<void>
{
    static const bool enabled = true;
    static const int COLUMNS = 80;
    static const int LINES = 24;
    static const int TAB_SIZE = 8;
};

__END_SYS

#include __ARCH_TRAITS_H
#include __HEADER_MACH(config)
#include __MACH_TRAITS_H

__BEGIN_SYS

template <> struct Traits<Application>: public Traits<void>
{
    static const unsigned int STACK_SIZE = 16 * 1024;
    static const unsigned int HEAP_SIZE = 16 * 1024 * 1024;
};

template <> struct Traits<System>: public Traits<void>
{
    static const unsigned int mode = Traits<Build>::MODE;
    static const bool multithread = true;
    static const bool multitask = false && (mode != Traits<Build>::LIBRARY);
    static const bool multicore = false && multithread;
    static const bool multiheap = (mode != Traits<Build>::LIBRARY)
        || Traits<Scratchpad>::enabled;

    static const bool reboot = true;

    static const unsigned int STACK_SIZE = 4 * 1024;
    static const unsigned int HEAP_SIZE =
        128 * Traits<Application>::STACK_SIZE;
};


// Abstractions
template <> struct Traits<Thread>: public Traits<void>
{
    static const bool smp = Traits<System>::multicore;

    typedef Scheduling_Criteria::Round_Robin Criterion;
    static const unsigned int QUANTUM = 10000; // us

    static const bool trace_idle = false;
};

template <> struct Traits<Task>: public Traits<void>
{
    static const bool enabled = Traits<System>::multitask;
};

template <> struct Traits<Address_Space>: public Traits<void>
{
    static const bool enabled = Traits<System>::multiheap;
};

template <> struct Traits<Segment>: public Traits<void>
{
    static const bool enabled = Traits<System>::multiheap;
};

template <> struct Traits<Alarm>: public Traits<void>
{
    static const bool visible = false;
};

template <> struct Traits<Synchronizer>: public Traits<void>
{
    static const bool enabled = Traits<System>::multithread;
};

__END_SYS

#endif
