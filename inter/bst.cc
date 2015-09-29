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

int main()
{
	test_findSecondLargest();
}
