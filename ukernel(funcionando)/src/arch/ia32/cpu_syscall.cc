// EPOS IA32 CPU System Call Function Implementation

#include <arch/ia32/cpu.h>
#include <ic.h>

__BEGIN_SYS

int IA32::syscall(void * m)
{
    Reg32 ret;
    ASM("int %1" : "=a"(ret) : "i"(IC::INT_SYSCALL), "a"(m));
    return ret;
}

__END_SYS
