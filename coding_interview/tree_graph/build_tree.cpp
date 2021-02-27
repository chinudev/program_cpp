#include <vector>
using namespace std;

//1,3,5, 11,12,13, 15, 16
//1,3,5,11,13
// take middle element  len/2, 5=>2   4=>2

class Node 
{
public:
    Node(int _value) : left(nullptr), right(nullptr), value(_value) {}
    Node *left, *right;
    int value;
};


Node* makeTree(vector<int>& values, int leftIndex, int rightIndex)
{
    if (rightIndex < leftIndex) return nullptr;

    int midIndex = (leftIndex + rightIndex)/2; 
    auto newNode = new Node(values[midIndex]);

    newNode->left = makeTree(values, leftIndex, midIndex-1);
    newNode->right = makeTree(values, midIndex+1, rightIndex);
    return newNode; 
}

Node* makeTree(vector<int>& values)
{
    return makeTree(values, 0, values.size()-1);
}


int main()
{
}

