#include <stub/semaphore.h>
//#include <stub/alarm.h>
//#include <stub/condition.h>
//#include <stub/address_space.h>
//#include <stub/segment.h>
//#include <stub/mutex.h>
//#include <stub/task.h>
//#include <stub/ostream.h>
//#include <stub/thread.h>

using namespace EPOS::APP;

int fn(int,int,int,int);
void fun_void(void);

int main()
{
    EPOS::S::OStream cout;


    //Address_Space address;
   // cout << "Addres Space=" << &address;

    //Segment segment1 (16*1024);
    //cout << ">>>>>>>>>>>>>>>>>>>>>Segment 1 = " << (void*) &segment1;
//    cout << "Stub Test!" << endl;

    //Log_Addr log_addr = address.attach(segment1);
    //address.detach(segment1);

    //Segment segment2 (log_addr, 16*1024);
    //cout << "Segment2=" << &segment2;

    //address.attach(segment2, log_addr);

   // cout << "Fuuuuusão: " << (char)(fn (65, 1, 1, 1)) << endl;

    //Thread t(&fn, 60,2,3,1);

   // cout << ">>> Retorno do JOIN: [[" << (char) t.join() << "]]" << endl;

//    cout << "KReat0Rs";


//    Function_Handler fh(&fun_void);
//    cout << "Function Handler=" << &fh;

//    Alarm alarm(1000000,&fh,1);
//    cout << "Alarm=" << &alarm;

//    Condition condition;
//    cout << "Condition=" << &condition;

//    Condition_Handler ch(&condition);
//    cout << "Condition Handler=" << &ch;

//    Mutex mutex;
//    cout << "Mutex=" << &mutex;

//    Mutex_Handler mh(&mutex);
//    cout << "Mutex Handler=" << &mh;


    Semaphore semaphore;
    cout << "Semaphore=" << &semaphore;

//    Semaphore_Handler sh(&semaphore);
//    cout << "Semaphore Handler=" << &sh;

//    //Task task(segment1, segment2);

//    Task *task = Task::self();
//    cout << "Task=" << task;

//    Alarm::delay(2000000);

    cout << "BYE";
    return 0;
}

int fn(int a, int b, int c, int d){
    EPOS::S::OStream cout;
    int e = a + b + c + d;
    cout << "Fn = {" << ((char) e) << "}" << "\n";
    return e;
}


//void fun_void(){
//    OStream cout;
//    Endl endl;
//    cout << "Oi sou uma função que não retorna nada Emoticon smile " << endl;
//}