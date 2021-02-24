
#include <algorithm>
#include <cmath>
#include <iostream> 


template <typename T> 
class Node
{
public: 
    Node(T& _value) : value(_value), left(nullptr), right(nullptr) {}
    ~Node() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }

    T value;
    Node<T>* left;
    Node<T>* right;

};

template <typename T> 
void printNode(Node<T>* head, int offset=0) 
{
    for (auto i=0; i < offset; i++) std::cout << "   ";
    if (head == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    } 
    std::cout << head->value << std::endl;

    printNode(head->left, offset+1);
    printNode(head->right, offset+1);
}

template <typename T> 
Node<T>* makeNode(T value, Node<T>* left = nullptr, Node<T>* right = nullptr) 
{
    auto newNode = new Node<T>(value);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}


