// EPOS Component Framework

#ifndef __framework_h
#define __framework_h

#include <cpu.h>
#include <mmu.h>
#include <task.h>
#include <thread.h>
#include <system.h>
#include <alarm.h>

#include "handle.h"

__BEGIN_API

typedef _SYS::CPU CPU;

typedef _SYS::OStream OStream;
using _SYS::endl;

typedef _CORE::System System;
typedef _CORE::Application Application;

typedef _SYS::Handle<_CORE::Thread> Thread;
typedef _SYS::Handle<_CORE::Active> Active;
typedef _SYS::Handle<_CORE::Task> Task;

typedef _SYS::Handle<_CORE::Address_Space> Address_Space;
typedef _SYS::Handle<_CORE::Segment> Segment;

typedef _SYS::Handle<_CORE::Mutex> Mutex;
typedef _SYS::Handle<_CORE::Semaphore> Semaphore;
typedef _SYS::Handle<_CORE::Condition> Condition;

typedef _SYS::Handle<_CORE::Clock> Clock;
typedef _SYS::Handle<_CORE::Chronometer> Chronometer;
typedef _SYS::Handle<_CORE::Alarm> Alarm;
typedef _SYS::Handle<_CORE::Delay> Delay;

typedef _SYS::Handle<_CORE::Display> Display;

__END_API

#endif
