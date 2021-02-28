#include <list>
#include <vector>
#include <iostream>
using namespace std;

/*
Is this a binary search tree ? No
straight path means : all left children, or all right children 
is one node a path : yes
are all values positive : no
*/

/*

  vector<int> all_sums 
  vector<path-list> all_paths

ask child for all_sums for a certain direction
- check if adding yourself creates the required sum. if yes, add to answer
- add yourself to all_sums based on what your parent asked and return
*/

class Node 
{
public:
    Node *left, *right;
    int value;
};

class SumPathPair 
{
public: 
    int sum;
    list<Node*> path;
};

vector<SumPathPair> findAllPaths(
    Node* head, 
    bool leftChild,
    const int gRequiredSum, 
    vector<list<Node*>>& gMatchingPaths)
{
    //vector<SumPathPair> returnVector;

    if (head == nullptr) return {};

    auto leftVector  = findAllPaths(head->left,  true,  gRequiredSum, gMatchingPaths);
    auto rightVector = findAllPaths(head->right, false, gRequiredSum, gMatchingPaths);


    for (auto& entry: leftVector) {
        entry.sum += head->value;
        entry.path.push_front(head);
        if (entry.sum == gRequiredSum) {
            gMatchingPaths.push_back(entry.path);
        }
    }
    for (auto& entry: rightVector) {
        entry.sum += head->value;
        entry.path.push_front(head);
        if (entry.sum == gRequiredSum) {
            gMatchingPaths.push_back(entry.path);
        }
    }


    if (head->value == gRequiredSum) {
        gMatchingPaths.push_back(list<Node*>{head});
    }

    if (leftChild) {
         leftVector.push_back(SumPathPair{head->value, list<Node*>{head}});
         return leftVector;
    } 
    // else

    rightVector.push_back(SumPathPair{head->value, list<Node*>{head}});
    return rightVector;
}

vector<list<Node*>> findAllPaths(Node* head, int gRequiredSum)
{
    vector<list<Node*>> gMatchingPaths;
    findAllPaths(head, true, gRequiredSum, gMatchingPaths);
    return gMatchingPaths;
}


int main()
{
}

