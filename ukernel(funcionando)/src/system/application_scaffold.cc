// EPOS Application Scaffold and Application Abstraction Implementation

#include <utility/ostream.h>
#include <application.h>
#include <system/framework.h>

// Application class attributes
__BEGIN_SYS
char Application::_preheap[];
Heap * Application::_heap;
__END_SYS

// Global objects
__BEGIN_API
OStream cout;
OStream cerr;
__END_API
