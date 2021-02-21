#include <iostream> 
#include <vector> 
#include <exception>
#include <algorithm>


using namespace std;

class Stack 
{
public: 
    void push(int val) 
    {
        valueStack.push_back(val);
        if (valueStack.size() == 1) {
            minStack.push_back(val);
        } else {
            minStack.push_back(std::min (val, this->min()));
        }
    }
    int pop() 
    {
        if (valueStack.size() == 0) {
            throw std::underflow_error("Popping an emtpy stack");
        }
        int value = valueStack.back();
        minStack.pop_back();
        valueStack.pop_back();
        return value;
    }

    int min() 
    {
        return minStack.back();
    }

private: 
    vector<int> valueStack;
    vector<int> minStack;
};


void test() 
{
    {
        Stack s; 
        //s.min() and s.pop() should throw exception 
        s.push(3);
        assert(s.min() == 3);
        s.push(1);
        assert(s.min() == 1);
        s.push(4);
        assert(s.min() == 1);
        assert(s.pop() == 4);
        assert(s.min() == 1);
        assert(s.pop() == 1);
        assert(s.min() == 3);
        assert(s.pop() == 3);
    }
}

int main(void) 
{
    test();
}
