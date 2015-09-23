#include <iostream>
#include <list>
#include <forward_list>
#include <map>
#include <assert.h>

using namespace std;

template <typename T>
class node 
{
public:
	node(T val): next(nullptr), prev(nullptr), value(val) {} 

	node(list<T> inList) {

		if (inList.empty()) throw runtime_error("Can't pass empty list to node ctor");

		auto iter = inList.begin();
		value = *iter;
		iter++;

		node *currNode = this;

		for (; iter != inList.end(); iter++) {
			node *newNode = new node(*iter);
			currNode->next = newNode;
			newNode->prev = currNode;
			currNode = newNode;
		}
	}

	node* next;
	node* prev;
	T value;
};


template <typename T>
void printList(node<T>* head) 
{
	for (; head != nullptr; head=head->next) {
		cout << head->value  << " -> ";
	}
	cout << "end" << endl;
}


/*

Remove duplicate from a list

*/

void removeDuplicate(list<int>& inList) 
{
	map<int,int> numberSet;

	for (auto iter=inList.begin(); iter != inList.end(); iter++) {
		if (numberSet[*iter] == 1) {
			iter = inList.erase(iter);
			// after deleting iter points to the next entry. We need
			//   to substract since for loop will also delete
			iter--;
		} else {
			numberSet[*iter]=1;
		}
	}

	for (auto elem: numberSet) {
		cout << elem.first << endl;
	}

}

void testRemoveDuplicate()
{
	list<int> list1 {1,4,2,4,2,3,3,2,4};

	for_each(list1.begin(), list1.end(), [](int& x) { cout << x << ","; }); cout << endl;
	removeDuplicate(list1);
	for_each(list1.begin(), list1.end(), [](int& x) { cout << x << ","; }); cout << endl;
}

/*

find kth to last entry in list

*/

int findKthLast(const forward_list<int>& numList, unsigned int k) 
{
	if (k < 1) return -1;

	auto rightIter = numList.begin();
	for (;k > 0 && rightIter != numList.end(); rightIter++, k--);

	if (k > 0) return -1;

	auto leftIter = numList.begin();
	for (; rightIter != numList.end(); leftIter++, rightIter++);

	return *leftIter;
}

void testKthLast()
{
	forward_list<int> list1 {1,2,3,4,5};
	forward_list<int> list2;

	assert(findKthLast(list1, 0) == -1);
	assert(findKthLast(list2, 1) == -1);

	assert(findKthLast(list1, 1) == 5);
	assert(findKthLast(list1, 2) == 4);
	assert(findKthLast(list1, 3) == 3);
	assert(findKthLast(list1, 4) == 2);
	assert(findKthLast(list1, 5) == 1);
	assert(findKthLast(list1, 6) == -1);

}


/*
Partition list
*/

template <typename T>
node<T>* partition(node<T> *head, T pivotValue) 
{
	// dummy nodes since we can't create empty nodes
	//  
	node<T> lesserHead(0); 
	node<T> greaterHead(0);

	node<T>* lesserNode  = &lesserHead;
	node<T>* greaterNode = &greaterHead;

	while (head != nullptr) {
		if (head->value < pivotValue) {
			lesserNode->next = head;
			head->prev = lesserNode;
			lesserNode = head;
		} else {
			greaterNode->next = head;
			head->prev = greaterNode;
			greaterNode = head;
		}
		head = head->next;
	}


	node<T> *newHead = lesserHead.next;
	if (newHead == nullptr) {
		newHead = greaterHead.next;
		greaterNode->next=nullptr;
	} else {
		if (greaterHead.next == nullptr) {
			lesserNode->next = nullptr;
		} else {
			lesserNode->next = greaterHead.next;
			greaterHead.next->prev = lesserNode;
			greaterNode->next = nullptr;
		}
	}

	return newHead;
}

void testPartition() 
{
	node<int> head1 ( list<int> {1,11,2,12,10,3,5,16,6} );

	printList(&head1);
	node<int> *newHead = partition(&head1, 10);
	printList(newHead);

}




int main()
{
	//testRemoveDuplicate();
	//testKthLast();
	testPartition();
}



