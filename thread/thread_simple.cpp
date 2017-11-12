#include <iostream>
#include <thread>
#include <string>

using namespace std;

void fn1()
{
    cout << " running inside fn1() " << endl;
}

class MyFunctor {
public:
    void operator()() {
        cout << " running inside functor" << endl;
    }

    void operator()(string& s1, string& s2, string& s3) {
        s1 += " updated ";
        s2 += " updated ";
        cout << " running inside functor "  << s1 << endl;
    }

};


void log(const string& msg) {

}

int main() 
{
    cout << "Main running with id " << this_thread::get_id() << endl;
    cout << "Ideal num thread = " << thread::hardware_concurrency() << endl;

    // Start a thread with plain old function 
    std::thread t1(fn1);
    cout << "Before t1.join " << endl;
    cout << "    t1 thread id = " << t1.get_id() << endl;
    cout << "    Is t1 joinable : " << t1.joinable() << endl;
    t1.join();
    cout << "After t1.join " << endl;
    cout << "    t1 thread id = " << t1.get_id() << endl;
    cout << "    Is t1 joinable : " << t1.joinable() << endl;

    // Start a thread with functor. 
    // Note extra paren around MyFunctor; that prevents t2 from 
    //   being considered a function
    std::thread t2(( MyFunctor() ));
    t2.detach();       // Detached thread needn't be joined. 
                       // Like a daemon except t2 will be killed if main exits. 


    // Start a thrad with functor + argument
    //   By default arguments are copied by value
    //   To pass by reference use std::ref or pointer
    //   To avoid extra copy, use std::move to "copy by value" without overhead
    std::string s1 = "#3", s2 = "#3", s3 = "#3";
    std::thread t3( (MyFunctor()), std::ref(s1), s2, std::move(s3));  
    t3.join();
    cout << " s1 = " << s1 << endl 
         << " s2 = " << s2 << endl;


}

