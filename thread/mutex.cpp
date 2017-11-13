#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std;



class Printer 
{
private:
    std::mutex printLock;
    std::once_flag flag;

public:

    void SetFlag() {
        std::call_once(flag, [](){ cout << "set_flag" << endl;}) ;

        // unique_lock is similar to lock_guard, except
        //   Can start off locked (default) or unlocked (defer_lock)
        //   Can unlock/lock explicitly  
        //   Can transfer ownership by doing std::move
        //   Is bit more expensive 
        //   
        std::unique_lock<std::mutex> guard(printLock, std::defer_lock);
        guard.lock();
        cout << " From locked section " << endl;
        guard.unlock();
    }

 
    void Print(const string& message) 
    {
        // call_once can be used for lazy initiliazation
        //   once_flag is more efficient than mutex. I think it is 
        //   implemented as double checked locking
        std::call_once(flag, [](){ cout << "locked_print" << endl;}) ;

        // lock_guard : a safer way than calling lock/unlock
        std::lock_guard<std::mutex> guard(printLock);
        //printLock.lock();
        cout << this_thread::get_id() << ": " << message << endl;
        //printLock.unlock();
    }

};



class MyFunctor {
    Printer& printer;
public:
    MyFunctor(Printer& pr) :  printer(pr) {}
    void operator()() {
        for (int i=0; i < 5; i++) {
            printer.Print("running inside functor");
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};


int main() 
{
    Printer myPrinter;
    myPrinter.SetFlag(); // Try commenting this out

    // Create 4 threads and launch
    const int NumThreads = 4;
    vector<std::thread> threadVec(NumThreads);
    for (int i=0; i < NumThreads; i++) {
        threadVec[i] = std::thread( (MyFunctor(myPrinter)) );
    }

    for (int i=0; i < NumThreads; i++) {
        threadVec[i].join();
    }
}


