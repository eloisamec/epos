#include <stub/semaphore.h>
#include <stub/alarm.h>
#include <stub/condition.h>
#include <stub/address_space.h>
#include <stub/segment.h>
#include <stub/mutex.h>
#include <stub/task.h>
//#include <stub/ostream.h>
#include <stub/thread.h>
//#include <utility/ostream.h>

__USING_APPLICATION

//int fn(int,int,int,int);
//void fun_void(void);

int main()
{
//    OStream cout;
//    EPOS::OStream cout;
//    Endl endl;
//    Hex hex;
//    Dec dec;

//    cout << "\n\n" << "### Stub Test!" << endl;

     int c = 45;
     Mutex mutex;
     c += 2;



//     Address_Space address;

//    cout << "Address space = " << &address << endl;

//    Segment * segment1 = new Segment(16*1024);
//    cout << "Segment 1 = " << segment1 << endl;
//    cout << "Meu tamanho é: " << segment1->size() << endl;

//    Log_Addr log_addr = address.attach(*segment1);
//    address.detach(*segment1);

    //    Segment segment2 (log_addr, 16*1024);
    //    cout << "Segment 2= " << &segment2;

    //    address.attach(segment2, log_addr);

    //    cout << "Função de char- " << (char)(fn (65, 1, 1, 1)) << endl;

//    Thread t(&fn, 60,2,3,1);

//    cout << "Retorno do JOIN: "<< dec << t.join() << endl;


//    Function_Handler fh(&fun_void);
//    cout << "Function Handler=" << &fh << endl;

//    Alarm alarm(10000,&fh,1);
//    cout << "Alarm=" << &alarm << endl;

//    Condition condition;
//    cout << "Condition=" << &condition << endl;

//    Condition_Handler ch(&condition);
//    cout << "Condition Handler=" << &ch << endl;

//    Mutex mutex;
//    cout << "Mutex=" << &mutex << endl;

//    Mutex_Handler mh(&mutex);
//    cout << "Mutex Handler=" << &mh << endl;


//    Semaphore semaphore;
//    cout << "Semaphore=" << &semaphore << endl;

//    Semaphore_Handler sh(&semaphore);
//    cout << "Semaphore Handler=" << &sh << endl;

    //    Task task1(segment1, segment2);

//    Task * task = Task::self();
//    cout << "Task=" << task << endl;

    //    Alarm::delay(2000000);

//    cout << "Fim do método main" << endl;
    return 0;
}

//int fn(int a, int b, int c, int d){
//    EPOS::OStream cout;
//    Endl endl;
//    int e = a + b + c + d;
//    cout << "Fn = {" << ((char) e) << "}" << "\n";
//    return e;
//}


//void fun_void(){
//    EPOS::OStream cout;
//    Endl endl;
//    cout << "Oi sou uma função que não retorna nada :) " << endl;
//}
