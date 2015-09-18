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




int main() 
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
