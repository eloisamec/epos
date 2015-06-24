#ifndef STUB_H
#define STUB_H

#include <system/config.h>

__BEGIN_APPLICATION

class Stub
{
protected:
    static void syscall(int * message){
        ASM("int $50" : : "eax"(message));
    }
};

__END_APPLICATION

#endif // STUB_H
