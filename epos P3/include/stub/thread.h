#ifndef __stub_THREAD_h
#define __stub_THREAD_h

#include <api_types.h>
#include <system/config.h>
#include <stub/task.h>
#include <stub/stub.h>

__BEGIN_APPLICATION

class Thread : Stub
{

private:
    Thread(int object_id) : _object_id(object_id) {}

public:

   Thread(int (* entry)()){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[5] {Class::THREAD, Method::Thread::CONSTRUCTOR_0, 0, 0, ientry};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(int (* entry)(int), int p2){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[6] {Class::THREAD, Method::Thread::CONSTRUCTOR_1, 0, 0, ientry, p2};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(int (* entry)(int, int), int p2, int p3){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[7] {Class::THREAD, Method::Thread::CONSTRUCTOR_2, 0, 0, ientry, p2, p3};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(int (* entry)(int, int, int), int p2, int p3, int p4){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[8] {Class::THREAD, Method::Thread::CONSTRUCTOR_3, 0, 0, ientry, p2, p3, p4};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(int (* entry)(int, int, int, int), int p2, int p3, int p4, int p5){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[9] {Class::THREAD, Method::Thread::CONSTRUCTOR_4, 0, 0, ientry, p2, p3, p4, p5};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(int (* entry)(int, int, int, int, int), int p2, int p3, int p4, int p5, int p6){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[10] {Class::THREAD, Method::Thread::CONSTRUCTOR_5, 0, 0, ientry, p2, p3, p4, p5, p6};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(int (* entry)(int, int, int, int, int, int), int p2, int p3, int p4, int p5, int p6, int p7){
       int ientry = reinterpret_cast<int>(entry);
       int * message = new int[11] {Class::THREAD, Method::Thread::CONSTRUCTOR_6, 0, 0, ientry, p2, p3, p4, p5, p6, p7};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   // task

   Thread(Task * task, int (* entry)()){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int * message = new int[6] {Class::THREAD, Method::Thread::CONSTRUCTOR_T_0, 0, 0, itask, ientry};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(Task * task, int (* entry)(int), int p3){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int * message = new int[7] {Class::THREAD, Method::Thread::CONSTRUCTOR_T_1, 0, 0, itask, ientry, p3};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(Task * task, int (* entry)(int,int), int p3, int p4){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int * message = new int[8] {Class::THREAD, Method::Thread::CONSTRUCTOR_T_2, 0, 0, itask, ientry, p3, p4};
       syscall(message);
       _object_id = message[2];
       delete message;
   }


   Thread(Task * task, int (* entry)(int,int, int), int p3, int p4, int p5){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int * message = new int[9] {Class::THREAD, Method::Thread::CONSTRUCTOR_T_3, 0, 0, itask, ientry, p3, p4, p5};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(Task * task, int (* entry)(int,int, int, int), int p3, int p4, int p5, int p6){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int * message = new int[10] {Class::THREAD, Method::Thread::CONSTRUCTOR_T_4, 0, 0, itask, ientry, p3, p4, p5, p6};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(Task * task, int (* entry)(int,int, int, int, int), int p3, int p4, int p5, int p6, int p7){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int * message = new int[11] {Class::THREAD, Method::Thread::CONSTRUCTOR_T_5, 0, 0, itask, ientry, p3, p4, p5, p6, p7};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   // configuration

   Thread(const Configuration & conf, int (* entry)()){
       int ientry = reinterpret_cast<int>(entry);
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[6] {Class::THREAD, Method::Thread::CONSTRUCTOR_C_0, 0, 0, iconf, ientry};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, int (* entry)(int), int p3){
       int ientry = reinterpret_cast<int>(entry);
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[7] {Class::THREAD, Method::Thread::CONSTRUCTOR_C_1, 0, 0, iconf, ientry, p3};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, int (* entry)(int,int), int p3, int p4){
       int ientry = reinterpret_cast<int>(entry);
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[8] {Class::THREAD, Method::Thread::CONSTRUCTOR_C_2, 0, 0, iconf, ientry, p3, p4};
       syscall(message);
       _object_id = message[2];
       delete message;
   }


   Thread(const Configuration & conf, int (* entry)(int,int, int), int p3, int p4, int p5){
       int ientry = reinterpret_cast<int>(entry);
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[9] {Class::THREAD, Method::Thread::CONSTRUCTOR_C_3, 0, 0, iconf, ientry, p3, p4, p5};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, int (* entry)(int,int, int, int), int p3, int p4, int p5, int p6){
       int ientry = reinterpret_cast<int>(entry);
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[10] {Class::THREAD, Method::Thread::CONSTRUCTOR_C_4, 0, 0, iconf, ientry, p3, p4, p5, p6};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, int (* entry)(int,int, int, int, int), int p3, int p4, int p5, int p6, int p7){
       int ientry = reinterpret_cast<int>(entry);
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[11] {Class::THREAD, Method::Thread::CONSTRUCTOR_C_5, 0, 0, iconf, ientry, p3, p4, p5, p6, p7};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   // Task and Configuration

   Thread(const Configuration & conf, Task * task, int (* entry)()){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[7] {Class::THREAD, Method::Thread::CONSTRUCTOR_TC_0, 0, 0, iconf, itask, ientry};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, Task * task, int (* entry)(int), int p4){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[8] {Class::THREAD, Method::Thread::CONSTRUCTOR_TC_1, 0, 0, iconf, itask, ientry, p4};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, Task * task, int (* entry)(int,int), int p4, int p5){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[9] {Class::THREAD, Method::Thread::CONSTRUCTOR_TC_2, 0, 0, iconf, itask, ientry, p4, p5};
       syscall(message);
       _object_id = message[2];
       delete message;
   }


   Thread(const Configuration & conf, Task * task, int (* entry)(int,int, int), int p4, int p5, int p6){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[10] {Class::THREAD, Method::Thread::CONSTRUCTOR_TC_3, 0, 0, iconf, itask, ientry, p4, p5, p6};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   Thread(const Configuration & conf, Task * task, int (* entry)(int,int, int, int), int p4, int p5, int p6, int p7){
       int ientry = reinterpret_cast<int>(entry);
       int itask = task->_object_id;
       int iconf = reinterpret_cast<int>(&conf);
       int * message = new int[11] {Class::THREAD, Method::Thread::CONSTRUCTOR_TC_3, 0, 0, iconf, itask, ientry, p4, p5, p6, p7};
       syscall(message);
       _object_id = message[2];
       delete message;
   }

   ~Thread(){
       int * message = new int[3] {Class::THREAD, Method::Thread::DESTRUCTOR, _object_id};
       syscall(message);
       delete message;
   }


   enum State {
       RUNNING,
       READY,
       SUSPENDED,
       WAITING,
       FINISHING
   };

   enum Criterion {
       HIGH,
       NORMAL,
       LOW
   };

   volatile State & state(){
       int * message = new int[4] {Class::THREAD, Method::Thread::STATE, _object_id, 0};
       syscall(message);
       volatile State* state = reinterpret_cast<State*>(message[3]);
       delete message;
       return *state;
   }

   volatile Priority & get_priority(){
       int * message = new int[4] {Class::THREAD, Method::Thread::GET_PRIORITY, _object_id, 0};
       syscall(message);
       volatile Priority* priority = reinterpret_cast<Priority*>(message[3]);
       delete message;
       return *priority;
   }

   void set_priority(const Priority & priority){
       int ipriority = reinterpret_cast<int>(&priority);
       int * message = new int[5] {Class::THREAD, Method::Thread::STATE, _object_id, 0, ipriority};
       syscall(message);
       delete message;

   }

   Task * task(){
       int * message = new int[4] {Class::THREAD, Method::Thread::TASK, _object_id, 0};
       syscall(message);
       Task * task = reinterpret_cast<Task*>(message[3]);
       delete message;
       return task;
   }

   int join (){
       int * message = new int[4] {Class::THREAD, Method::Thread::JOIN, _object_id, 0};
       syscall(message);
       int status = message[3];
       delete message;
       return status;
   }

   void pass (){
       int * message = new int[4] {Class::THREAD, Method::Thread::PASS, _object_id, 0};
       syscall(message);
       delete message;
   }

   void suspend (){
       int * message = new int[4] {Class::THREAD, Method::Thread::SUSPEND, _object_id, 0};
       syscall(message);
       delete message;
   }

   void resume(){
       int * message = new int[4] {Class::THREAD, Method::Thread::RESUME, _object_id, 0};
       syscall(message);
       delete message;
   }

   static Thread * self (){
       int * message = new int[4] {Class::THREAD, Method::Thread::SELF, 0, 0};
       syscall(message);
       Thread * thread = reinterpret_cast<Thread*>(message[3]);
       delete message;
       return thread;
   }

   static void yield (){
       int * message = new int[4] {Class::THREAD, Method::Thread::YIELD, 0, 0};
       syscall(message);
       delete message;
   }

   static void exit (int status = 0){
       int * message = new int[5] {Class::THREAD, Method::Thread::EXIT, 0, 0, status};
       syscall(message);
       delete message;
   }


private:
   int _object_id;
};

__END_APPLICATION

#endif
