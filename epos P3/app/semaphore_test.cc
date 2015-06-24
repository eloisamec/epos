#include <stub/semaphore.h>
#include <utility/ostream.h>

EPOS::OStream cout;
using EPOS::S::endl;

int main(){


    cout << "Criando semaforo" << endl;
    EPOS::Semaphore sem;
    EPOS::Semaphore_Handler sh(&sem);
    cout << "SIM SIM!" << endl;

    return 0;


}
