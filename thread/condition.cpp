#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <chrono>
#include <vector>
#include <condition_variable>
#include <assert.h>

using namespace std;


std::vector<int> vec;
std::mutex mu;
std::condition_variable cond;

class Producer {
public:
    void operator()() {
        for (int i=0; i<10; i++) {

            unique_lock<mutex> locker(mu);
            cout << " Generating job " << i << endl;
            vec.push_back(i);
            locker.unlock();
            cond.notify_one();
            this_thread::sleep_for(chrono::seconds(1));
        }

        // kill all threads
        unique_lock<mutex> locker(mu, std::defer_lock);
        for (int i=0; i<10; i++) { // assuming max 10 threads 
            vec.push_back(-1);
        }
        cond.notify_all();
    }
};

class Consumer {
public:

    void operator()() {
        cout << this_thread::get_id() << ": Started" << endl;

        while (1) {

            // On wait acquird lock is released. On condition signal, 
            //  lock is acquired. However if predicate is not met, C++ will 
            //  autoatically do another wait (release lock and wait). 
            // That's why we can't use a guard_lock
            //   
            unique_lock<mutex> locker(mu);
            cond.wait(locker, []() {return !vec.empty();} );

            assert(vec.size() > 0);
            int cmd = vec.back();
            vec.pop_back();
            locker.unlock();

            if (cmd == -1) {
                cout << this_thread::get_id() << ": Exited" << endl;
                return;
            }

            cout << this_thread::get_id() << ": " << cmd << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};



int main() 
{

    const int NumThreads = 4;
    vector<std::thread> consumerVec(NumThreads);
    for (int i=0; i < NumThreads; i++) {
        consumerVec[i] = std::thread( (Consumer()) );
    }

    std::thread producer( (Producer()) );

    producer.join();
    for (int i=0; i < NumThreads; i++) {
        consumerVec[i].join();
    }

}

