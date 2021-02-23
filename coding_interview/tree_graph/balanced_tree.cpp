#include <algorithm>
#include <cmath>
#include <iostream> 
#include "tree.h"


// return -1 if the node is not balanced. 
// if the tree is balanced, return the height of the node
template <typename T>
int _isBalanced(const Node<T>* head) 
{
    if (head == nullptr) {
        return 0;
    }
    int leftHeight = _isBalanced(head->left);
    int rightHeight = _isBalanced(head->right);
    if ((leftHeight < 0) || (rightHeight < 0)) return -1;
    if (abs(leftHeight - rightHeight) <= 1) return 1+std::max(leftHeight, rightHeight);
    return -1;
}

template <typename T>
bool isBalanced(const Node<T>* head) 
{
    return (_isBalanced(head) >= 0);
}



int main(void)
{
    {
        auto head = makeNode<int>(1, 
                                  makeNode<int>(2, 
                                                makeNode<int>(3),
                                                makeNode<int>(4)));
        /*
        printNode(head);
        std::cout << _isBalanced(head) << std::endl;
        std::cout << _isBalanced(head->left) << std::endl;
        std::cout << _isBalanced(head->right) << std::endl;
        */
        assert(isBalanced(head) == false);
        delete head;
    }
    {
        auto head = makeNode<int>(1, 
                                  makeNode<int>(2, 
                                                makeNode<int>(3)),
                                  makeNode<int>(5));
        assert(isBalanced(head) == true);
        delete head;
    }
}
