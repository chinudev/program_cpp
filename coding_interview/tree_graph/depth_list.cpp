#include <vector>
using namespace std;

class TreeNode 
{
public: 
    TreeNode(int _value) : left(nullptr), right(nullptr), value{_value} {}
    TreeNode *left, *right;
    int value;
};

class ListNode 
{
public: 
    ListNode(int _value) : next(nullptr), value{_value} {}
    ListNode *next;
    int value;
};


// how do we deal with nullptr => skip them
// return a vector of Node*. 
// Do we leave the tree intact. 


void _makeSiblingList(const TreeNode* head, int depth, vector<ListNode*>& sibVector)
{
    if (head == nullptr) return;

    auto newNode = new ListNode(head->value);
    if (sibVector.size() < depth) {
        sibVector.push_back(newNode);
        assert(sibVector.size() == depth);
    } else {
        assert(sibVector[depth-1] != nullptr);
        newNode->next = sibVector[depth-1];
        sibVector[depth-1] = newNode;
    }

    // visit the right child first since we are pushing entries backwards..
    _makeSiblingList(head->right, depth+1, sibVector);
    _makeSiblingList(head->left, depth+1, sibVector);

}

vector<ListNode*> makeSiblingList(const TreeNode* head)
{
    vector<ListNode*> sibVector;
    _makeSiblingList(head, 1, sibVector);
    return sibVector;
}

int main()
{
}
