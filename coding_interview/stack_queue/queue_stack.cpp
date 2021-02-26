#include <vector>
#include <stdexcept>


template <typename T>
class Stack
{
public: 
    void push(T val) 
    {
        stackVector.push_back(val);
    }

    T pop() 
    {
        if (stackVector.size() <= 0) {
            throw std::out_of_range("Popping an empty stack");
        }
        T val = stackVector.back();
        stackVector.pop_back();
        return val;
    }

    int size()
    {
        return stackVector.size();
    }
    
private: 
    std::vector<T> stackVector;
};


template <typename T>
class MyQueue 
{
public:
    void enqueue(T val) 
    {
        firstStack.push(val);
    }

    T dequeue() 
    {
        if (secondStack.size() <= 0) {
            if (firstStack.size() <= 0) {
                throw std::out_of_range("No elements in the queue");
            }
            while (firstStack.size() > 0) {
                secondStack.push( firstStack.pop() );
            }
        }
        return secondStack.pop();
    }


private:
    Stack<T> firstStack;  // Put elements here in stack order. New values go there first
    Stack<T> secondStack; // This contains elements in queue order. Lazy load this.
};



int main(void) 
{
    {
        MyQueue<int> q;
        q.enqueue(1);
        q.enqueue(2);
        assert(q.dequeue() == 1);
        q.enqueue(3);
        q.enqueue(4);
        assert(q.dequeue() == 2);
        assert(q.dequeue() == 3);
        assert(q.dequeue() == 4);
    }
}
