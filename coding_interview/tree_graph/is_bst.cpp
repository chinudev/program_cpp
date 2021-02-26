#include <limits>

class  Node 
{
public: 
    Node *left, *right;
    int value;
};

// Assuming that there can be duplicate values and 
//  the same value goes to the left child.. 
bool isBST(const Node* head, 
           int min=std::numeric_limits<int>::min(), 
           int max=std::numeric_limits<int>::max()) 
{
    if (head == nullptr) return true; 
    // min < head->value <= max 
    if (head->value <= min) return false; 
    if (head->value > max) return false; 

    return isBST(head->left, min, head->value) && 
           isBST(head->right, head->value , max);
}


int main()
{
}
