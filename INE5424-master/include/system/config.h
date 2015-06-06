// EPOS Configuration Engine

#ifndef __config_h
#define __config_h

//============================================================================
// DEFINITIONS
//============================================================================

namespace EPOS {
    namespace S {
        namespace C {}
    }
    namespace U {}
}

#define __BEGIN_SYS             namespace EPOS { namespace S {
#define __END_SYS               }}
#define _SYS                    ::EPOS::S
#define __USING_SYS             using namespace EPOS::S;

#define __BEGIN_CORE            namespace EPOS { namespace S {
#define __END_CORE              }}
#define _CORE                   ::EPOS::S

#define __BEGIN_API             namespace EPOS {
#define __END_API               }
#define _API                    ::EPOS

#define ASM                     __asm__ __volatile__

#define __HEADER_ARCH(X)        <arch/ARCH/X.h>
#define __HEADER_MACH(X)        <mach/MACH/X.h>
#define __MACH_TRAITS_T(X)      <mach/MACH/X##_traits.h>
#define __MACH_TRAITS(X)        __MACH_TRAITS_T(X)
#define __MACH_CONFIG_T(X)      <mach/MACH/X##_config.h>
#define __MACH_CONFIG(X)        __MACH_CONFIG_T(X)
#define __APPL_TRAITS_T(X)      <../app/X##_traits.h>
#define __APPL_TRAITS(X)        __APPL_TRAITS_T(X)

//============================================================================
// ARCHITECTURE, MACHINE, AND APPLICATION SELECTION
// This section is generated automatically from makedefs
//============================================================================
#define ARCH xxx
#define MACH xxx
#define MMOD xxx
#define APPL xxx

#define __ARCH_TRAITS_H         __HEADER_ARCH(traits)
#define __MACH_TRAITS_H         __MACH_TRAITS(MMOD)
#define __MACH_CONFIG_H         __MACH_CONFIG(MMOD)
#define __APPL_TRAITS_H         __APPL_TRAITS(APPL)

//============================================================================
// ASSERT (for pre and post conditions)
//============================================================================
//#define assert(expr)    ((expr) ? static_cast<void>(0) : Assert::fail (#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__))
#define assert(expr)    (static_cast<void>(0))

//============================================================================
// CONFIGURATION
//============================================================================
#include <system/types.h>
#include <system/meta.h>
#include __APPL_TRAITS_H
#include <system/info.h>

//============================================================================
// THINGS EVERBODY NEEDS
//============================================================================
#include <utility/ostream.h>
#include <utility/debug.h>

#endif
