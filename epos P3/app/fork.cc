// EPOS Task Test Program

#include <stub/ostream.h>
#include <stub/alarm.h>
#include <stub/thread.h>
#include <stub/task.h>

using namespace EPOS::APPLICATION;

const int iterations = 10;

int func_a(void);
int func_b(void);

Thread * a;
Thread * b;
Thread * m;


int main()
{
    OStream cout;
    Endl endl;

    cout << "Task test" << endl;

    m = Thread::self();

    cout << "I'll try to clone myself:" << endl;

    Task * task0 = Task::self();
    Address_Space * as0 = task0->address_space();

    cout << "My address space's page directory is located at " << "as0->pd()" << endl;

    Segment * cs0 = task0->code_segment();
    Log_Addr code0 = task0->code();
    cout << "My code segment is located at "
         << static_cast<void *>(code0)
         << " and it is " << cs0->size() << " bytes long" << endl;

    Segment * ds0 = task0->data_segment();
    Log_Addr data0 = task0->data();
    cout << "My data segment is located at "
         << static_cast<void *>(data0)
         << " and it is " << ds0->size() << " bytes long" << endl;

    cout << "Creating and attaching segments:" << endl;
    Segment cs1(cs0->size());
    Log_Addr code1 = as0->attach(cs1);
    cout << "  code => " << "code1" << " done!" << endl;
    Segment ds1(ds0->size());
    Log_Addr data1 = as0->attach(ds1);
    cout << "  data => " << "data1 "<< " done!" << endl;

    cout << "&code0=" << &code0 << endl;
    cout << "&code1=" << &code1 << ", size=" << cs0->size() << endl;

    cout << "Copying segments:";
    memcpy(code1, code0, cs1.size());
    cout << " code => done!" << endl;
    memcpy(data1, data0, ds1.size());
    cout << " data => done!" << endl;

    cout << "Detaching segments:";
    as0->detach(cs1);
    as0->detach(ds1);
    cout << " done!" << endl;

    cout << "Creating the clone task:";
    Task * task1 = new Task(cs1, ds1);
    cout << " done!" << endl;

    cout << "Creating a thread over the cloned task:";
    a = new Thread(task1, &func_a);
    cout << " done!" << endl;

    cout << "Creating a thread over the main task:";
    b = new Thread(&func_b);
    cout << " done!" << endl;

    cout << "I'll now suspend my self to see the other threads running:" << endl;
    m->suspend();

    cout << "Both threads are now done and have suspended themselves. I'll now wait for 1 second and then wake them up so they can exit ..." << endl;

    Alarm::delay(1000000);

    a->resume();
    b->resume();

    int status_a = a->join();
    int status_b = b->join();

    cout << "Thread A exited with status " << status_a << " and thread B exited with status " << status_b << "." << endl;

    delete a;
    delete b;
    delete task1;

    cout << "I'm also done, bye!" << endl;

    return 0;
}


int func_a(void)
{
    OStream cout;
    Endl endl;

    for(int i = iterations; i > 0; i--) {
        for(int i = 0; i < 79; i++)
            cout << "a";
        cout << endl;
        Thread::yield();
    }

    Thread::self()->suspend();
    return 'A';
}

int func_b(void)
{
    OStream cout;
    Endl endl;

    for(int i = iterations; i > 0; i--) {
        for(int i = 0; i < 79; i++)
            cout << "b";
        cout << endl;
        Thread::yield();
    }

    m->resume();

    Thread::self()->suspend();
    return 'B';
}
