#include <vector>
#include <iostream> 
#include <assert.h> 

using namespace std;


/*

100 cents..
 99c + 1
 98c + 2
 ...
 95c + 5c, or 95 + 5*1c

 1 c
 0c + 25

26c = 25,1  1,25 

0 , 25 
0, 5, 10, 15, 20 , 25
0,1,2,3,4,5(2), 6(2)

6 ( 1...1, 1,5) => 2
7 (1...1, 1+1+5) => 2
11 (1...1, 1+5+5, 5+1..1) => 3
*/

// coinVector should have coin in decreasing order.
unsigned int findNumWays( 
    const vector<unsigned int>& coinVector, 
    unsigned int target)
{
    vector<int> numWays(target+1, 0);
    numWays[0] = 1;

    for (auto coin: coinVector) {
        //cout << "processing " << coin << endl;
        if (target < coin) continue;
        for (int i=0; i <= target - coin; i++) {
            numWays[i + coin] += numWays[i];
            //cout << "processing " << i  << "+" << coin << "=" << numWays[i+coin]<< endl;
        }
    }
    cout << numWays[target] << endl;
    return numWays[target];
}

int main()
{
    vector<unsigned int> coinVector = {25, 10, 5, 1}; 

    assert(findNumWays(coinVector, 0) == 1);
    assert(findNumWays(coinVector, 1) == 1);
    assert(findNumWays(coinVector, 2) == 1);
    assert(findNumWays(coinVector, 6) == 2);  
    assert(findNumWays(coinVector, 7) == 2);
    assert(findNumWays(coinVector, 11) == 4);

}






