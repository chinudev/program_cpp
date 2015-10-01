#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

// travel an n-ary tree post-order 

struct Node {
public:
	Node(int val) :value(val) {}
	int value;
	vector<Node *> children;
};


template <typename OP>
void postOrder(Node* root, OP operation) 
{
	// Boolean tracks if the node has been visited once or not. 
	// We will push a node into stack with visited boolean=false. 
	// Once we pop a node, we push it back with boolean = true and push back its children also. 

	using NodePair = pair<Node *, bool>;
	stack<NodePair> nodeStack;

	if (root == nullptr) return;
	nodeStack.push(make_pair(root, false));

	while (!nodeStack.empty()) {
		if (nodeStack.top().second == false) { 
			// we are visiting this node for the first time 
			// add the children
			nodeStack.top().second=true;
			for (auto child: nodeStack.top().first->children) {
				nodeStack.push(make_pair(child, false));
			}
		} else {
			// we are visiting the node second time. We should process it this time
			operation(nodeStack.top().first->value);
			nodeStack.pop();
		}
	}
}


class Printer {
public:
	void operator ()(const int val) { cout << val << endl;}
};


void testPostOrder() 
{
	Node root(10); 
	Printer printer;

	postOrder(&root, printer);

	root.children.push_back(new Node(20));
	root.children.push_back(new Node(30));
	root.children.push_back(new Node(40));
	postOrder(&root, printer);
}



int main()
{
	testPostOrder();
}

