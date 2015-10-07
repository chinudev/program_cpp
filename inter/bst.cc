#include <iostream>
#include <assert.h>


using namespace std;

struct Node {
public:
	Node(int val) : value(val), left(nullptr), right(nullptr) {}
	int value;
	Node *left;
	Node *right;
};

int findSecondLargest(const Node* root) 
{
	if (root == nullptr) throw std::runtime_error("not enough entries");

	const Node* tailer = nullptr;

	while (root->right != nullptr) {
		tailer = root;
		root = root->right;
	}

	// root is now pointing at the largest element.


	if (root->left != nullptr) {
		tailer = root->left;
		while (tailer->right != nullptr) tailer = tailer->right;
		return tailer->value;
	}
	else {
		if (tailer == nullptr) throw std::runtime_error("not enough entries");
		return tailer->value;
	}

	assert(false); // should never reach here
}


void test_findSecondLargest()
{
	Node *root = nullptr;
	{
		bool caught = false;
		try {
			findSecondLargest(root);
		} 
		catch(...) {
			caught=true;
		}
		assert(caught == true);
	}

	root = new Node(10); 
	{
		bool caught = false;
		try {
			findSecondLargest(root);
		} 
		catch(...) {
			caught=true;
		}
		assert(caught == true);
	}

	root->left = new Node(5); 
	assert(findSecondLargest(root) == 5);

	root->left->right = new Node(8); 
	assert(findSecondLargest(root) == 8);

	root->right = new Node(20); 
	assert(findSecondLargest(root) == 10);

	root->right->right = new Node(30); 
	root->right->right->left = new Node(25); 
	assert(findSecondLargest(root) == 25);
}


//
// Find minimun value in a given range from BST
//
const Node* findMinInRange(const Node* root, int min, int max)
{
	if (root == nullptr) return nullptr;
	//cout <<  "iterating : " << root->value << " with min/max " << min << " " << max << endl;


	// Check left sub-tree to find min value
	if (root->value > min) {
		const Node *minNode = findMinInRange(root->left, min, max);
		if (minNode != nullptr) return minNode;
	}

	// Check if this node is the answer
	if (root->value >= min and root->value <= max) return root;

	// Check right sub-tree for answer
	if (root->value < max)return findMinInRange(root->right, min, max);

	return nullptr;
}

void test_findMin()
{
	Node *root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->left->right = new Node(8);
	root->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right = new Node(18);

	assert(findMinInRange(nullptr,0,0) == nullptr);
	assert(findMinInRange(root,0,0) == nullptr);
	assert(findMinInRange(root,1,2) == nullptr);
	assert(findMinInRange(root,1,3)->value == 3);
	assert(findMinInRange(root,7,13)->value == 8);
}


int main()
{
	test_findSecondLargest();
	test_findMin();
}
