 // EPOS Semaphore Abstraction Test Program
 
#include <stub/address_space.h>
#include <stub/semaphore.h>
#include <stub/mutex.h>
#include <stub/task.h>
#include <stub/segment.h>
#include <utility/ostream.h>

using namespace EPOS::APP;

EPOS::S::OStream cout;

int main(){

    Semaphore * ad = new Semaphore(1);

    Address_Space * as = new Address_Space();
    Mutex * table = new Mutex();

    Segment * es1 = new Segment();
	//Segment * es2 = new Segment(16*1024);
    cout << "  extra segment 1 => " << ES1_SIZE << " bytes, done!" << EPOS::S::endl;
    //cout << "  extra segment 2 => " << ES2_SIZE << " bytes, done!" << EPOS::S::endl;

   //  as->attach1(*es1);
    //cout << "  extra segment 1 => " << extra1 << " done!" << EPOS::S::endl;
	//Task * tsk = new Task(es1, es2);

    cout << "Rodou" << EPOS::S::endl;
    return 0;
}



