#include <list>
#include <iostream>

/*
           100
     50           200
  60    70     20     150

 (60,50) -> 50
 (60,70) -> 50
 (60,20) -> 100
*/

class Node {
public: 
    Node *left, *right;
};

// return a path starting from the 
bool findPath(const Node* head, const Node* node, std::list<const Node*>& path)
{
    if (head == nullptr) return false;
    if (head == node) {
        assert(path.size() == 0);
        path.push_front(head);
        return true;
    }

    if ((findPath(head->left,  node, path) == true) ||
        (findPath(head->right, node, path) == true)) {
        
        path.push_front(head);
        return true;
    }
    return false;
}


const Node* findCommonAncestor(
    const Node* head, 
    const Node* left, 
    const Node* right)
{
    std::list<const Node*> leftList, rightList;

    if (findPath(head, left,  leftList)  == false) return nullptr;
    if (findPath(head, right, rightList) == false) return nullptr;

    assert(leftList.front()  == head);
    assert(rightList.front() == head);

    const Node* answer = head;
    while (leftList.front() == rightList.front()) {
        answer = leftList.front();
        leftList.pop_front();
        rightList.pop_front();
    }
    return answer;
}


int main()
{
}


