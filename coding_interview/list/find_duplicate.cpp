
#include "list.hpp" 
#include <unordered_set>



// Modify the list in place
template<typename T> 
Node<T>* _removeDuplicates(Node<T>* head) 
{
    if (head == nullptr) return nullptr;
    unordered_set<T> valueSet;
    valueSet.insert(head->data);

    Node<T>* curr = head;
    while (curr->next) {
        Node<T>* nextNode = curr->next;
        if (valueSet.find(nextNode->data) == valueSet.end()) {
            valueSet.insert(nextNode->data);
            curr = curr->next;
        } else {
            curr->next = nextNode->next;
            delete nextNode;
        }
    }
    return head;
}


template<typename T> 
Node<T>* removeValue(Node<T>* head, const T& value) 
{

    while ((head != nullptr) && (head->data == value)) {
        Node<T>* newHead = head->next;
        delete head;
        head = newHead;
    }
    if (head == nullptr) return nullptr;


    Node<T>* curr = head;
    while (curr->next != nullptr) {
        Node<T>* nextNode = curr->next;
        if (nextNode->data == value) {
            // remove duplicate
            curr->next = nextNode->next;
            delete nextNode;
        } else {
            // keep going
            curr = curr->next;
        }
    }
    return head;
}

// Solve the problem without using additional space 
template<typename T> 
Node<T>* removeDuplicates(Node<T>* head) 
{

    Node<T>* current = head; 
    while (current != nullptr) {
        current->next = removeValue(current->next, current->data);
        current = current->next;
    }
    return head;
}




void test() 
{
    {
        auto input = makeList({1,2,3,1,1,1});
        auto expected = makeList({1,2,3});
        auto output = removeDuplicates(input);
        printList(output);
        assert( compareList(output, expected));
    }
    {
        auto input = makeList({2,3,1,1,1});
        auto expected = makeList({2,3,1});
        auto output = removeDuplicates(input);
        printList(output);
        assert( compareList(output, expected));
    }
    {
        auto input = makeList({2,3,1,1,1,2,3});
        auto expected = makeList({2,3,1});
        auto output = removeDuplicates(input);
        printList(output);
        assert( compareList(output, expected));
    }
    {
        auto input = makeList({1,1,1});
        auto expected = makeList({1});
        auto output = removeDuplicates(input);
        printList(output);
        assert( compareList(output, expected));
    }
    {
        auto input = makeList<int>({});
        auto expected = makeList<int>({});
        auto output = removeDuplicates(input);
        printList(output);
        assert( compareList(output, expected));
    }
}

int main(void) 
{
    test();
}
