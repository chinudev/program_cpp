#include "list.hpp"

/* 
1 -> 2 -> 3 -> 5 -> null

findKToLast(head, 3) == <2>
findKToLast(head, 1) == 5
findKToLast(head, 0) == nullptr 
findKToLast(head, 4) == 1
findKToLast(head, 5) == nullptr

1 -> null
findKToLast(head, 1) == 1
findKToLast(head, 0) == nullptr
findKToLast(head, 2) == nullptr

findKToLast(nullptr, 1) == nullptr
*/
// Linked list .. 
// 4 min to think
// 8:42 to write.. 


template <typename T>
const Node<T>* findKToLast (const Node<T>* head, unsigned int k) 
{
    if (k <= 0) return nullptr;
    const Node<T>* tailNode = head;

    for (auto i=0; i < k; i++) {
        if (head == nullptr) return nullptr; 
        head = head->next;
    }

    while (head) {
        head = head->next;
        tailNode = tailNode->next;
    }
    return tailNode;
}

void test()
{
    {
        auto head = makeList<int>({});
        printList(head);
        assert(findKToLast(head, 0) == nullptr);
        assert(findKToLast(head, 1) == nullptr);
        assert(findKToLast(head, 100) == nullptr);
    }
    {
        auto head = makeList({1});
        printList(head);
        assert(findKToLast(head, 0) == nullptr);
        assert(findKToLast(head, 1)->data == 1);
        assert(findKToLast(head, 2) == nullptr);
    }
    {
        auto head = makeList({1,2,3,4});
        printList(head);
        assert(findKToLast(head, 0) == nullptr);
        assert(findKToLast(head, 1)->data == 4);
        assert(findKToLast(head, 2)->data == 3);
        assert(findKToLast(head, 3)->data == 2);
        assert(findKToLast(head, 4)->data == 1);
    }
}

int main(void) 
{
    test();
}


