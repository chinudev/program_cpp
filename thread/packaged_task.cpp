#include <iostream>
#include <string>
#include <chrono>

#include <thread>
#include <future>
#include <assert.h>

using namespace std;


int factorial(int n) {
    int result = 1;
    while (n > 1) result *= n--;
    cout << "   In factorial method" <<  endl;
    return result;
}



int main() 
{

    std::packaged_task<int(int)> t(factorial);
    // Unlike std::thread, to bind param need to use std::bind.
    std::packaged_task<int()> t2(std::bind(factorial,6));

    // .. 
    //
    cout << "In main thread " << endl;

    //int a = t(6);  // Not allowed
    t(6);
    int a = t.get_future().get();
    cout << "Result = " << a << endl;

    t2();
    int b = t2.get_future().get();
    cout << "Result = " << b << endl;



}

