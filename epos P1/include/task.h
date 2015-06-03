#ifndef __task_h
#define __task_h

#include <address_space.h>
#include <segment.h>
#include <mmu.h>
#include <system.h>
#include <utility/list.h>

__BEGIN_SYS

class Task
{
   friend class System;
   friend class Thread;

public:
   Task();
   Task(const Segment & cs, const Segment & ds);
   ~Task();

   Address_Space * address_space() const;
   Segment * code_segment() const;
   Segment * data_segment() const;
   CPU::Phy_Addr code() const;
   CPU::Phy_Addr data() const;
   static Task * self();

   void insert(Thread * t);
   void remove(Thread * t);

private:
   //Manter uma referência das threads da instância
   Address_Space * _address_space;
   Segment * _code_segment;
   Segment * _data_segment;
   CPU::Phy_Addr _code;
   CPU::Phy_Addr _data;

   void activate() const { _address_space->activate(); };
   
   static void init();
   
   static Simple_List<Thread> _threads;
   static Task * _master;
};

__END_SYS

#include <thread.h>

#endif