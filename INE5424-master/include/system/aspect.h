// EPOS Aspect Programs

#ifndef __aspect_h
#define __aspect_h

#include <aspect/identified.h>

__BEGIN_SYS

class Null_Aspect {};

template <typename Aspect, bool active>
class Conditional_Aspect: public  Aspect {};

template <typename Aspect>
class Conditional_Aspect<Aspect, false>: public Null_Aspect {};

template<typename Component>
class Aspects: public Conditional_Aspect<Identified<Component>, Traits<Component>::identified>
{
};

__END_SYS

#endif
