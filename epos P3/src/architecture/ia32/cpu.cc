// EPOS IA32 CPU Mediator Implementation

#include <architecture/ia32/cpu.h>
#include <thread.h>
#include <system/memory_map.h>

__BEGIN_SYS

// Class attributes
unsigned int IA32::_cpu_clock;
unsigned int IA32::_bus_clock;

// Class methods
void IA32::Context::save() volatile
{
    // Save the running thread context into its own stack (mostly for debugging)
    ASM("     push    %ebp                                            \n"
        "     mov     %esp, %ebp                                      \n"
        "     mov     8(%ebp), %esp   # sp = this                     \n"
        "     add     $40, %esp       # sp += sizeof(Context)         \n"
        "     push    4(%ebp)         # push eip                      \n"
        "     pushf                                                   \n"
        "     push    %eax                                            \n"
        "     push    %ecx                                            \n"
        "     push    %edx                                            \n"
        "     push    %ebx                                            \n"
        "     push    %ebp            # push esp                      \n"
        "     push    (%ebp)          # push ebp                      \n"
        "     push    %esi                                            \n"
        "     push    %edi                                            \n"
        "     mov     %ebp, %esp                                      \n"
        "     pop     %ebp                                            \n");
}

void IA32::Context::load() const volatile
{
    // Pop the context pushed into the stack during thread creation to initialize the CPU's context
    // POPA ignores the SP saved by PUSHA. SP is just normally incremented
    // IRET will pop FLAGS, CS, and IP
    ASM("       mov     4(%esp), %esp         # sp = this           \n"
        "       popa                                                \n");
    ASM("       iret                                                \n");  // Chama "iret"
}

void IA32::switch_context(Context * volatile * o, Context * volatile n)
{
    // Recover the return address from the stack and
    // save the previously running thread context ("o") into its stack
    // PUSHA saves an extra SP (which is always "this"), but saves several instruction fetches
    ASM("       pop     %esi                    # eip               \n"
        "       pushf                                               \n"
        "       push    %cs                                         \n"
        "       push    %esi                    # eip               \n"
        "       pusha                                               \n");
    ASM("       mov     44(%esp), %eax          # old               \n"
        "       mov     %esp, (%eax)                                \n");


    // Restore the next thread context ("n") from its stack
    ASM("       mov     48(%esp), %esp          # new           \n");


    Reg32 esp0 = 0;
    ASM("mov %%esp, %0" : "=r"(esp0));

    // will pop FLAGS, CS, and IP
    ASM("       popa                                            \n");

    TSS * tss0 = reinterpret_cast<TSS*>(Memory_Map<PC>::TSS0);
    tss0->esp0 = esp0;

    // Change context through the IRET
    ASM("iret");

}

__END_SYS
