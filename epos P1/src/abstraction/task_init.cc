#include <utility/elf.h>
#include <mmu.h>
#include <system.h>
#include <task.h>

__BEGIN_SYS

void Task::init()
{
	System_Info<Machine> * si = System::info();

    _master = new (SYSTEM) Task();
    _master->_address_space = new (SYSTEM) Address_Space (MMU::current());
    _master->_code_segment = new (SYSTEM) Segment (CPU::Phy_Addr(si->lm.app_code), si->lm.app_code_size);
    _master->_data_segment = new (SYSTEM) Segment (CPU::Phy_Addr(si->lm.app_data), si->lm.app_data_size);
    _master->_code = CPU::Phy_Addr(Memory_Map<Machine>::APP_CODE);
    _master->_data = CPU::Phy_Addr(Memory_Map<Machine>::APP_DATA);
}

__END_SYS