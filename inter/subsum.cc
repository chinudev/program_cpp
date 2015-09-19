#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


// Return true if any sub-sequence in 'seq' sums up to the targetSum
//   assumption: sequence doesn't contain any -ve numbers
bool isSumPresent(const vector<int> seq, const int targetSum) 
{
	if (targetSum == 0) return true;
	if (seq.empty()) return false;

	// Initialize loop variables
	auto leftIter = seq.begin();
	auto rightIter = seq.begin();
	int sum = *rightIter;

	while (1) {
		while (sum < targetSum) {
			rightIter++;
			if (rightIter == seq.end()) return false;

			sum += *rightIter;
		}
		
		while (sum > targetSum and leftIter <= rightIter) {
			sum -= *leftIter;
			leftIter++;
		}

		if (sum == targetSum) return true;
	}

	// we should never reach here. 
	assert(0);
}

// This is same as algorithm above, except it uses iterators
template <class iterator_type> 
bool isSumPresent2(iterator_type it, iterator_type end, const int targetSum) 
{
	if (targetSum == 0) return true;
	if (it == end) return false;      // no entries

	// Initialize loop variables
	auto leftIter = it;
	auto rightIter = it;
	int sum = *rightIter;

	while (1) {
		while (sum < targetSum) {
			rightIter++;
			if (rightIter == end) return false;

			sum += *rightIter;
		}
		
		while (sum > targetSum and leftIter <= rightIter) {
			sum -= *leftIter;
			leftIter++;
		}

		if (sum == targetSum) return true;
	}

	// we should never reach here. 
	assert(0);
}


// This algorithm doesn't assume there are -ve numbers
template <class iterator_type> 
bool isSubseqSumPresent(iterator_type it, iterator_type end, const int targetSum) 
{
/*
Given a sequence 1,2,3,-1,..  we compute a sequence of running sum
   viz.        0,1,3,6,5 ,..
Imagine this as a graph. Now if any two points differ by targetSum we can arrive
 at the target sum.
To find that we can sort the sum list and then try to find 2 numbers that differ by 
 targetSum. We should be able to figure that out in O(n)
*/

	if (it == end) return false;      // no entries

	vector<int> sumList {0};

	int runningSum=0;
	for (; it != end; it++) {
		runningSum += *it;
		sumList.push_back(runningSum);
	}

	//for (auto item: sumList) cout << item  << ","; cout << endl;

	// sort the sum list
	sort(sumList.begin(), sumList.end());

	//for (auto item: sumList) cout << item  << ","; cout << endl;

	// if the difference between 2 elements is targetSum, we have an answer
	auto leftIter = sumList.begin();
	auto rightIter = leftIter;
	
	for (; rightIter != end; rightIter++)  {
		while (leftIter != rightIter) {
			int diff = *rightIter - *leftIter;
			if (diff == targetSum) return true;
			if (diff < targetSum) break;

			// diff > targetSum, so we should move leftIter 
			leftIter++;
		}
	}
	return false;

}



// These test are for an algo that only handles sequence with postivie numbers
void test1() 
{
	vector<int> seq1;
	vector<int> seq2 {1,3};

	assert( isSumPresent(seq1, 0) == true);
	assert( isSumPresent(seq1, 3) == false);
	assert( isSumPresent(seq2, 1) == true);
	assert( isSumPresent(seq2, 3) == true);
	assert( isSumPresent(seq2, 2) == false);
	assert( isSumPresent(seq2, 4) == true);

	assert( isSumPresent2(seq2.begin(), seq2.end(), 4) == true);
	assert( isSumPresent2(seq2.begin(), seq2.end(), 2) == false);

	int arr[] = {2,5,7};
	assert( isSumPresent2(arr, arr+3,6) == false);
	assert( isSumPresent2(arr, arr+3,12) == true);
}

void test2() 
{
	vector<int> seq1 = {1,2,3,-3,-3,9};

	assert( isSubseqSumPresent(seq1.begin(), seq1.begin(), 0) == false);
	assert( isSubseqSumPresent(seq1.begin(), seq1.end(), 0) == true);
	assert( isSubseqSumPresent(seq1.begin(), seq1.begin()+3, 0) == false);
	assert( isSubseqSumPresent(seq1.begin(), seq1.end(), 3) == true);
	assert( isSubseqSumPresent(seq1.begin(), seq1.end(), 9) == true);
}


int main()
{
	test1();
	test2();
}

