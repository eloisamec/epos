// EPOS Semaphore Abstraction Test Program

#include <utility/ostream.h>
#include <thread.h>
#include <stub/mutex.h>
#include <stub/semaphore.h>
#include <stub/alarm.h>
#include <stub/display.h>

using namespace EPOS::APP;

const int iterations = 10;

Mutex table;

EPOS::S::Thread * phil[5];
Semaphore * chopstick[5];

EPOS::S::OStream cout;
Display display;
int philosopher(int n, int l, int c)
{
	
    int first = (n < 4)? n : 0;
    int second = (n < 4)? n + 1 : 4;

    for(int i = iterations; i > 0; i--) {

        table.lock();
        display.position(l, c);
        cout << "thinking";
        table.unlock();

        Alarm::delay(2000000);

        chopstick[first]->p();   // get first chopstick
        chopstick[second]->p();   // get second chopstick

        table.lock();
        display.position(l, c);
        cout << " eating ";
        table.unlock();

        Alarm::delay(1000000);

        chopstick[first]->v();   // release first chopstick
        chopstick[second]->v();   // release second chopstick
    }

    table.lock();
    display.position(l, c);
    cout << "  done  ";
    table.unlock();

    return iterations;
}

int main()
{
    table.lock();
    display.clear();
    display.position(0, 0);
    cout << "The Philosopher's Dinner:" << EPOS::S::endl;

    for(int i = 0; i < 5; i++)
        chopstick[i] = new Semaphore;

    phil[0] = new EPOS::S::Thread(&philosopher, 0,  5, 32);
    phil[1] = new EPOS::S::Thread(&philosopher, 1, 10, 44);
    phil[2] = new EPOS::S::Thread(&philosopher, 2, 16, 39);
    phil[3] = new EPOS::S::Thread(&philosopher, 3, 16, 24);
    phil[4] = new EPOS::S::Thread(&philosopher, 4, 10, 20);

    cout << "Philosophers are alive and hungry!" << EPOS::S::endl;

    display.position(7, 44);
    cout << '/';
    display.position(13, 44);
    cout << '\\';
    display.position(16, 35);
    cout << '|';
    display.position(13, 27);
    cout << '/';
    display.position(7, 27);
    cout << '\\';
    display.position(19, 0);

    cout << "The dinner is served ..." << EPOS::S::endl;
    table.unlock();

    for(int i = 0; i < 5; i++) {
        int ret = phil[i]->join();
        table.lock();
        display.position(20 + i, 0);
        cout << "Philosopher " << i << " ate " << ret << " times " << EPOS::S::endl;
        table.unlock();
    }

    for(int i = 0; i < 5; i++)
        delete chopstick[i];
    for(int i = 0; i < 5; i++)
        delete phil[i];

    cout << "The end!" << EPOS::S::endl;

    return 0;
}
