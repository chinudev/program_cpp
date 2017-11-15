#include <iostream>
#include <string>
#include <chrono>

#include <future>
#include <assert.h>

using namespace std;


int factorial(int n) {
    int result = 1;
    while (n > 1) result *= n--;
    return result;
}


int fact2(std::future<int>& f) {
    cout << "Inside fact2 " << endl;
    int n = f.get();
    return factorial(n);
}

int fact3(std::shared_future<int> f) {
    cout << this_thread::get_id() << " : started " << endl;
    int n = f.get();
    cout << this_thread::get_id() << " : unblocked " << endl;
    return factorial(n);
}

int main() 
{

    // async will cause a new thread to be launched
    std::future<int> f1 = std::async(std::launch::async, factorial, 4);

    // Deferred will use the main thread when f2.get() is called
    auto f2 = std::async(std::launch::deferred, factorial, 5);

    // Default leaves choice upto compiler implementation
    auto f3 = std::async(factorial, 6);


    // Get blocks this thread until future is ready. Similar to join but you 
    //   get the return value back. 
    int r3 = f3.get();
    int r2 = f2.get();
    int r1 = f1.get();

    cout << " r1 = " << r1 << endl;
    cout << " r2 = " << r2 << endl;
    cout << " r3 = " << r3 << endl;


    // Promise can be used to send something to a child (or to anyone I guess)
    std::promise<int> p;
    auto f4 = p.get_future();

    auto f5 = std::async(std::launch::async, fact2, std::ref(f4));

    cout << "In main thread " << endl;
    std::this_thread::sleep_for(chrono::milliseconds(20));
    p.set_value(7);
    cout << " async value = " << f5.get() << endl;



    // Shared future can be used to broadcast 
    std::promise<int> sp; 
    std::shared_future<int> sf = sp.get_future().share();

    // Note we don't need to use ref; it is ok to copy shared_future by value
    auto fu1 = std::async(std::launch::async, fact3, sf);
    auto fu2 = std::async(std::launch::async, fact3, sf);
    auto fu3 = std::async(std::launch::async, fact3, sf);

    cout << " sleep in main thread " << endl;
    std::this_thread::sleep_for(chrono::milliseconds(20));
    cout << " awake in main thread " << endl;

    sp.set_value(6);

    fu1.get();
    fu2.get();
    fu3.get();


}

