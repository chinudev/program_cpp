#include "list.hpp"

/*
 1->2->3->4->null
 delete(head, 1) => 2
 delete(head, 3) => 1
 delete(head, 5) => nullptr
*/

template <typename T> 
Node<T>* deleteNode(Node<T>* head, Node<T>* nodeToDelete)
{
    if (head == nullptr) return nullptr;
    if (head == nodeToDelete) {
        head = head->next;
        delete nodeToDelete;
        return head;
    }

    Node<T>* currNode = head;
    while (currNode->next) {
        if (currNode->next == nodeToDelete) {
            currNode->next = currNode->next->next;
            delete nodeToDelete;
            return head;
        }
        currNode = currNode->next;
    }
    return nullptr;
}

/*
1->2->3->null

delete(3) = false
delete(2) = true
delete(1) = true
delete(null) = false
*/

template <typename T> 
bool deleteN( Node<T>* node) 
{
    if ((node == nullptr) || (node->next == nullptr)) return false; 
    auto nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
    return true;
}



int main(void)
{
    {
        // memory leaks since we never delete lists but ok for test
        auto head = makeList({1,2,3,4});
        head = deleteNode(head, head);
        assert( compareList(head, makeList({2,3,4})) );

        assert( head == deleteNode(head, head->next));
        assert( compareList(head, makeList({2,4})) );

        deleteNode(head, head->next);
        assert( compareList(head, makeList({2})) );

        Node<int>* nullNode = nullptr;
        assert( deleteNode(head, nullNode) == nullptr );
        assert(nullptr == deleteNode(head, head));
        assert(nullptr == deleteNode(nullNode, head));
    }

    {
        Node<int>* tempNode = nullptr;
        assert(deleteN(tempNode) == false);

        auto head = makeList({1,2,3});
        assert(deleteN(head) == true);
        //printList(head);
        assert(deleteN(head->next) == false);
        assert(deleteN(head) == true);
        //printList(head);

    }
}
