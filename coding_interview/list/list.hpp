#include <iostream>
#include <initializer_list>
using namespace std;


template <typename T> 
class Node 
{
public: 
    Node(T _data): next(nullptr), data(_data) {}

    Node* next;
    T data;
};



template <typename T> 
Node<T>* makeList(std::initializer_list<T> list) 
{
    Node<T> *head = nullptr;
    Node<T> *curr = nullptr;

    for (auto elem: list) {
        Node<T>* newNode = new Node<T>(elem);
        if (curr) {
            curr->next = newNode;
            curr = curr->next;
        } else {
            head = newNode;
            curr = head;
        }
    }
    return head;
}

template <typename T> 
void printList(const Node<T>* head) 
{
    while (head) {
        cout << head->data << " => ";
        head = head->next;
    }
    cout << " <nullptr> " << endl;
}

// Return true if both the lists are the same
template <typename T> 
bool compareList(const Node<T>* head1, const Node<T>* head2) 
{
    while ((head1 != nullptr) && (head2 != nullptr)) {
        if (head1->data != head2->data) {
            break;
        } else {
            head1 = head1->next;
            head2 = head2->next;
        }
        
    }
    if ((head1 == nullptr) && (head2 == nullptr)) return true;
    return false;

}
