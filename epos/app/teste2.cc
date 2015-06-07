 // EPOS Semaphore Abstraction Test Program
 
#include <stub/address_space.h>
#include <stub/semaphore.h>
#include <stub/mutex.h>
#include <stub/task.h>
#include <segment.h>
 #include <utility/ostream.h>
//#include <table_class_method.h>

#include <system/config.h>

using namespace EPOS::APP;

EPOS::S::OStream cout;

const unsigned ES1_SIZE = 10000;
const unsigned ES2_SIZE = 100000;

int main(){


    Semaphore * ad = new Semaphore(1);

    Address_Space * as = new Address_Space();
    Mutex * table = new Mutex();

   EPOS::S::Segment * es1 = new EPOS::S::Segment(ES1_SIZE);
   EPOS::S::Segment * es2 = new EPOS::S::Segment(ES2_SIZE);
    cout << "  extra segment 1 => " << ES1_SIZE << " bytes, done!" << EPOS::S::endl;
    cout << "  extra segment 2 => " << ES2_SIZE << " bytes, done!" << EPOS::S::endl;

   //  as->attach1(*es1);
    //cout << "  extra segment 1 => " << extra1 << " done!" << EPOS::S::endl;
	Task * tsk = new Task(&es1,&es2);

    cout << "Rodou" << EPOS::S::endl;
    return 0;
}



