// use -std=c++11  flag for g++

#include <iostream> 
#include <vector>
#include <list>

using namespace std;

void test1() 
{
	vector<int> v; 
	for (auto i=0; i<10; i++) v.push_back(i*i);

	for (auto elem: v) cout << elem << ",";
	cout << endl;

	// Remove odd elements
	for (auto iter=v.begin(); iter != v.end(); iter++) {
		if (*iter % 2 == 1) {
			v.erase(iter--); 
		}
	}

	sort(v.rbegin(), v.rend());

	for (auto iter=v.begin(); iter != v.end(); iter++) cout << *iter << ",";
	cout << endl;
}

// test some algorithms
void test2() 
{
	list<int> intList;

	for (auto i=0; i <10; i++) intList.push_back(i+1); 

	// print all elem
	for_each(intList.begin(), intList.end(), [](int& x) { cout << x << ",";} ); 
	cout << endl;

	// subtract 1 from each entry
	for_each(intList.begin(), intList.end(), [](int& x) { x--;} ); 

	// print each entry in a different way
	copy_if(intList.begin(), intList.end(), 
	        ostream_iterator<int>(cout), 
		[](int& x) -> bool { return x % 2 == 0;});
	cout << endl;

	// count
	cout << "Multiples of 3 = " 
	     << count_if(intList.begin(), intList.end(), [](int& x) -> bool { return x!=0 && (x % 3 == 0); })
	     << endl;


}



int main()
{
	//test1();
	test2();


}


