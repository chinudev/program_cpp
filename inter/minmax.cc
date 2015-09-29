#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
#include <assert.h>

using namespace std; 


class MinMaxTracker
{
public: 
	int L1,L2,L3; // Largest numbers. L1 >= L2 >= L3
	int S1,S2,S3; // Smallest numbers. S1 <= S2 <= S3

	MinMaxTracker() {
		L1=L2=L3=INT_MIN;
		S1=S2=S3=INT_MAX;
	}

	void add(const int elem)  {
		// Update the largest elements
		if (elem > L1) {
			L3=L2; L2=L1; L1=elem;
		} else if (elem > L2) {
			L3=L2; L2=elem;
		} else if (elem > L3) {
			L3=elem;
		}

		// Update the smallest elements
		if (elem < S1) {
			S3=S2; S2=S1; S1=elem;
		} else if (elem < S2) {
			S3=S2; S2=elem;
		} else if (elem < S3) {
			S3=elem;
		}
	}


};

tuple<int,int,int> findMaxProduct( const vector<int> numVector) 
{
	MinMaxTracker tracker;

	for (const int& elem: numVector) tracker.add(elem);

	if (tracker.L1 >= 0) {
		if (tracker.L2*tracker.L3 >= tracker.S1*tracker.S2) {
			return make_tuple(tracker.L1, tracker.L2, tracker.L3);
		} else {
			return make_tuple(tracker.L1, tracker.S2, tracker.S1);
		}
	} else {
		// all numbers are -ve. We must try to minimize the product
		return make_tuple(tracker.L1, tracker.L2, tracker.L3);
	}
}


void test_findMax()
{
	{
		vector<int> vec {1,2,3};
		assert( findMaxProduct(vec) == make_tuple(3,2,1) );
	}
	{
		vector<int> vec {1,-2,-3};
		assert( findMaxProduct(vec) == make_tuple(1,-2,-3) );
	}
	{
		vector<int> vec {1,2,3,-2,-3};
		assert( findMaxProduct(vec) == make_tuple(3,-2,-3) );
	}
	{
		vector<int> vec {0,99,100,-2,-3};
		assert( findMaxProduct(vec) == make_tuple(100,-2,-3) );
	}
	{
		vector<int> vec {1,2,3,4,5,6};
		assert( findMaxProduct(vec) == make_tuple(6,5,4) );
	}
	{
		vector<int> vec {-3,-9,-2,-3};
		auto tup = findMaxProduct(vec);
		//int a,b,c;
		//tie(a,b,c) = tup;
		//cout << a << ":" << b << ":" << c <<  endl;
		assert( findMaxProduct(vec) == make_tuple(-2,-3,-3) );
	}
}


int main()
{
	test_findMax();
}


