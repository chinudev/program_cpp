
#include "list.hpp" 
#include <unordered_set>



// Modify the list in place
template<typename T> 
Node<T>* removeDuplicates(Node<T>* head) 
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
