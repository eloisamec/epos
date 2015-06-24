// EPOS Task Abstraction Initialization

#include <utility/elf.h>
#include <mmu.h>
#include <system.h>
#include <task.h>

__BEGIN_SYS

void Task::init()
{
    db<Init, Task>(TRC) << "Task::init()" << endl;

    System_Info<Machine> * si = System::info();

    _master = new (SYSTEM) Task (new (SYSTEM) Address_Space(MMU::current()),
                                 new (SYSTEM) Segment(Log_Addr(si->lm.app_code), si->lm.app_code_size),
                                 new (SYSTEM) Segment(Log_Addr(si->lm.app_data), si->lm.app_data_size),
                                 CPU::Log_Addr(Memory_Map<Machine>::APP_CODE),
                                 CPU::Log_Addr(Memory_Map<Machine>::APP_DATA));

    db<Init, Task>(INF) << "Task::master=" << _master << " => {as=" << _master->_as << ",cs=" << _master->_cs << ",ds=" << _master->_ds << ",code=" << _master->_code << ",data=" << _master->_data << "}" << endl;

    if(si->bm.extras_offset != -1)
        db<Init>(INF) << "Task:: additional tasks at "  << reinterpret_cast<void *>(si->lm.app_extra) << ":" << si->lm.app_extra_size << endl;
}

__END_SYS
