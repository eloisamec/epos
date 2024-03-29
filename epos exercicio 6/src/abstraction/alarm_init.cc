// EPOS Alarm Abstraction Initialization

//#include <system/kmalloc.h>
#include <system.h>
#include <alarm.h>

__BEGIN_SYS

void Alarm::init()
{
    db<Init, Alarm>(TRC) << "Alarm::init()" << endl;

    _timer = new (SYSTEM) Alarm_Timer(handler);
}

__END_SYS
