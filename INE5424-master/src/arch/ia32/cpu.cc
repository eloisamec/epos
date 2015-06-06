// EPOS IA32 CPU Mediator Implementation

#include <arch/ia32/cpu.h>
#include <system.h>
#include <ic.h>

extern "C" { void _exec(void *); }

__BEGIN_SYS

// Class attributes
unsigned int IA32::_cpu_clock;
unsigned int IA32::_bus_clock;

// Class methods
void IA32::Context::save() volatile
{
    ASM("	pushl	%ebp						\n"
 	"	movl	%esp, %ebp					\n"
        "	movl    8(%ebp), %esp	# sp = this	 		\n"
        "	addl    $40, %esp      	# sp += sizeof(Context)		\n"
        "	pushl	4(%ebp)		# push eip			\n"
        "	pushfl							\n"
        "	pushl	%eax						\n"
        "	pushl	%ecx						\n"
        "	pushl	%edx						\n"
        "	pushl	%ebx						\n"
        "	pushl   %ebp		# push esp			\n"
        "	pushl   (%ebp)		# push ebp			\n"
        "	pushl	%esi						\n"
        "	pushl	%edi						\n"
        "	movl    %ebp, %esp					\n"
        "	popl    %ebp						\n");
}

void IA32::Context::load() const volatile
{
    if(Traits<System>::mode == Traits<Build>::KERNEL) {
        // Discards the context pushed into the stack during thread creation but the entry point (eip)
        ASM("       movl    4(%esp), %esp       # sp = this             \n"
            "       popal                       # pop context           \n"
            "       popfl                                               \n");

        // Reload Segment Registers with user-level selectors
        ASM("       mov     %0, %%ds                                    \n"
            "       mov     %0, %%es                                    \n"
            "       mov     %0, %%fs                                    \n"
            "       mov     %0, %%gs                                    \n"
            : : "r"(SEL_APP_DATA));

        // Restore the thread's entry point left on the stack while initializing its context
        ASM("       popl    %esi                # si = this->_eip       \n");

        // Fake a cross-level stack for a return from kernel to user-level: ss, esp, eflags, cs, eip
        ASM("       pushl   %0                                          \n"
            "       pushl   %2                                          \n"
            "       pushf                                               \n"
            "       pushl   %1                                          \n"
            "       push    %%esi                                       \n"
            "       iret                                                \n"
            : : "r"(SEL_APP_DATA), "r"(SEL_APP_CODE), "r"(System::info()->lm.app_heap));
    } else
        // POPA ignores the ESP saved by PUSHA. ESP is just normally incremented
        ASM("	    movl    4(%esp), %esp	# sp = this     	\n"
            "       popal				        	\n"
            "	    popfl					        \n");
}

void IA32::switch_context(Context * volatile * o, Context * volatile n)
{
    // PUSHA saves an extra "esp" (which is always "this"),
    // but saves several instruction fetchs.
    ASM("	pushfl				\n"
        "	pushal				\n"
        "	movl    40(%esp), %eax	# old	\n" 
        "	movl    %esp, (%eax)		\n"
        "	movl    44(%esp), %esp	# new	\n"
        "	popal				\n"
        "	popfl				\n");
}

int IA32::syscall(void * m)
{
    int ret = 0;
    ASM("int %1" : "=a"(ret) : "i"(IC::INT_SYSCALL), "a"(m));
    return ret;
}

void IA32::syscall_entry()
{
    // Do the system call by calling _exec with the message pointed by AX
    ASM("       pushl   %eax                                            \n"
        "       call    _exec                                           \n"
        "       popl    %eax                                            \n"
        "       iret                                                    \n");
}

__END_SYS
