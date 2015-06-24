#include <stub/thread.h>
#include <stub/ostream.h>
#include <stub/alarm.h>
#include <stub/mutex.h>

__USING_APPLICATION

int fun_b(){
    OStream cout;
    //Mutex m;
    cout << "=============================>FUN!!\n";
    int esp0 = 0;
    ASM("mov %%cs, %0" : "=r"(esp0));
    if(esp0 == 8){
        cout << "fun_b em modo Sistema\n";
    } else {
        cout << "fun_b em modo Usuário\n";
    }
    cout << "Oi de novo\n";
   return -2;
}

int main(){
    OStream cout;

    int esp0 = 0;
    ASM("mov %%cs, %0" : "=r"(esp0));
    if(esp0 == 8){
        cout << "Main em modo Sistema (" << esp0 << ")\n";
    } else {
        cout << "Main em modo Usuário(" << esp0 << ")\n";
    }

    Thread * t = new Thread(&fun_b);

    cout << "=============================>Main!!\n";

    t->join();
    cout << "Saindo...\n";

    delete t;

    return 0;
}
