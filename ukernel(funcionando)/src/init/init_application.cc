// EPOS Application Initializer

#include <utility/heap.h>
#include <mmu.h>
#include <machine.h>
#include <application.h>
#include <address_space.h>
#include <segment.h>

extern "C" { char _end; } // defined by GCC

__BEGIN_SYS

class Init_Application
{
private:
    static const unsigned int HEAP_SIZE = Traits<Application>::HEAP_SIZE;
    static const unsigned int STACK_SIZE = Traits<Application>::STACK_SIZE;

public:
    Init_Application() {
        db<Init>(TRC) << "Init_Application()" << endl;

        // Only the boot CPU runs INIT_APPLICATION on non-kernel mode
        if(Traits<System>::mode != Traits<Build>::KERNEL) {
            Machine::smp_barrier();
            if(Machine::cpu_id() != 0)
                return;
        }

        // Initialize Application's heap
        db<Init>(INF) << "Initializing application's heap: " << endl;
        if(Traits<System>::multiheap) { // Heap in data segment arranged by SETUP
            char * stack = MMU::align_page(&_end);
            char * heap = stack + MMU::align_page(Traits<Application>::STACK_SIZE);
            Application::_heap = new (&Application::_preheap[0]) Heap(heap, HEAP_SIZE);
        } else
            for(unsigned int frames = MMU::allocable(); frames; frames = MMU::allocable())
                System::_heap->free(MMU::alloc(frames), frames * sizeof(MMU::Page));
        db<Init>(INF) << "done!" << endl;
    }
};

// Global object "init_application"  must be linked to the application (not
// to the system) and there constructed at first.
Init_Application init_application;

__END_SYS
