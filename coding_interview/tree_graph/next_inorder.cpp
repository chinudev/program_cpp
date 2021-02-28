


/*
     100
  50        200
25   75  150   250
            175
*/

class Node 
{
public: 
    Node* left, *right, *parent;
};


Node* findInorder(Node* node) 
{
    if (node == nullptr) return nullptr;

    
    // if node has right-child, next in-order will be the left-most
    //   node in the sub-tree of right-child. 
    if (node->right != nullptr) {
        Node* nextNode = node->right;
        while (nextNode->left != nullptr) {
            nextNode = nextNode->left;
        }
        return nextNode;
    }

    // if the node doesn't have right-child, one of the parent will be 
    //   the next in-order but only if child is the left-child of the parent.

    while (node->parent != nullptr) {
        Node* parent = node->parent;
        if (parent->left == node) {
            return parent;
        }
        node = parent;
    }

    return nullptr;
}

int main()
{
}
