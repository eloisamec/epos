// EPOS Semaphore Abstraction Test Program

#include <utility/ostream.h>
#include <thread.h>
#include <stub/mutex.h>
#include <stub/semaphore.h>
#include <alarm.h>
#include <display.h>

using namespace EPOS;

const int iterations = 10;

Mutex table;
S::Thread * phil[5];
Semaphore * chopstick[5];

OStream cout;

int philosopher(int n, int l, int c)
{
    int first = (n < 4)? n : 0;
    int second = (n < 4)? n + 1 : 4;

    for(int i = iterations; i > 0; i--) {

        table.lock();
        S::Display::position(l, c);
        cout << "thinking";
        table.unlock();

        S::Delay thinking(2000000);

        chopstick[first]->p();   // get first chopstick
        chopstick[second]->p();   // get second chopstick

        table.lock();
        S::Display::position(l, c);
        cout << " eating ";
        table.unlock();

        S::Delay eating(1000000);

        chopstick[first]->v();   // release first chopstick
        chopstick[second]->v();   // release second chopstick
    }

    table.lock();
    S::Display::position(l, c);
    cout << "  done  ";
    table.unlock();

    return iterations;
}

int main()
{
    table.lock();
    S::Display::clear();
    S::Display::position(0, 0);
    cout << "The Philosopher's Dinner:" << S::endl;

    for(int i = 0; i < 5; i++)
        chopstick[i] = new EPOS::Semaphore;

    phil[0] = new S::Thread(&philosopher, 0,  5, 32);
    phil[1] = new S::Thread(&philosopher, 1, 10, 44);
    phil[2] = new S::Thread(&philosopher, 2, 16, 39);
    phil[3] = new S::Thread(&philosopher, 3, 16, 24);
    phil[4] = new S::Thread(&philosopher, 4, 10, 20);

    cout << "Philosophers are alive and hungry!" << S::endl;

    S::Display::position(7, 44);
    cout << '/';
    S::Display::position(13, 44);
    cout << '\\';
    S::Display::position(16, 35);
    cout << '|';
    S::Display::position(13, 27);
    cout << '/';
    S::Display::position(7, 27);
    cout << '\\';
    S::Display::position(19, 0);

    cout << "The dinner is served ..." << S::endl;
    table.unlock();

    for(int i = 0; i < 5; i++) {
        int ret = phil[i]->join();
        table.lock();
        S::Display::position(20 + i, 0);
        cout << "Philosopher " << i << " ate " << ret << " times " << S::endl;
        table.unlock();
    }

    for(int i = 0; i < 5; i++)
        delete chopstick[i];
    for(int i = 0; i < 5; i++)
        delete phil[i];

    cout << "The end!" << S::endl;

    return 0;
}
