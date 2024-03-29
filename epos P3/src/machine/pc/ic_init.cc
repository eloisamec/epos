// EPOS PC Interrupt Controller Initialization

#include <cpu.h>
#include <ic.h>
#include <stub/skeleton.h>

__BEGIN_SYS

void PC_IC::init()
{
    db<Init, IC>(TRC) << "IC::init()" << endl;

    CPU::int_disable();

    // Set all IDT entries to proper int_dispatch() offsets
    CPU::IDT_Entry * idt = reinterpret_cast<CPU::IDT_Entry *>(Memory_Map<PC>::IDT);
    for(unsigned int i = 0; i < CPU::IDT_ENTRIES; i++)
        if(i < INTS)
            idt[i] = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(entry) + i * 16, CPU::SEG_IDT_ENTRY);
        else
            idt[i] = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(entry) + CPU::EXC_LAST * 16, CPU::SEG_IDT_ENTRY);

    // Install some important exception handlers
    idt[CPU::EXC_PF]     = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(&exc_pf),  CPU::SEG_IDT_ENTRY);
    idt[CPU::EXC_DOUBLE] = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(&exc_pf),  CPU::SEG_IDT_ENTRY);
    idt[CPU::EXC_GPF]    = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(&exc_gpf), CPU::SEG_IDT_ENTRY);
    idt[CPU::EXC_NODEV]  = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(&exc_fpu), CPU::SEG_IDT_ENTRY);

    // Set all interrupt handlers to int_not()
    for(unsigned int i = 0; i < INTS; i++)
        _int_vector[i] = int_not;

    // Syscall
    void (*entry_skeleton)() = reinterpret_cast<void (*)()>(Skeleton::receive);
    idt[50] = CPU::IDT_Entry(CPU::SEL_SYS_CODE, Log_Addr(entry_skeleton), CPU::SEG_IDT_ENTRY);

    remap();
    disable();

    CPU::int_enable();
}

__END_SYS
