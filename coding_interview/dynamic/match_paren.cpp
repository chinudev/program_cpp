#include <iostream>
#include <vector>
#include <string>
using namespace std;


//
// ( ( )(
// at each level, we need to know how many open paren have been used, how many remain
/// we don't need to track close paren since by the end we must close.
// should we use vector<int> or string.. vector are easier 
// but strings should be more efficient if we can modify in place. 
//  with reserve, we will need to slot the new paren in correct index but should be doable
//  using ..but we need to track the index..


void findCombos(
    int leftParenUnmatched, 
    int leftParenAvailable, 
    string& str, 
    int strIndex,
    vector<string>& strVector)
{
    if (leftParenAvailable > 0) {
        str[strIndex] = '(';
        findCombos(leftParenUnmatched+1, leftParenAvailable-1, str, strIndex+1, strVector);
    }
    if (leftParenUnmatched > 0) {
        str[strIndex] = ')';
        findCombos(leftParenUnmatched-1, leftParenAvailable, str, strIndex+1, strVector);
    }
    if ((leftParenAvailable <= 0) && (leftParenUnmatched <= 0)) {
        str[strIndex]='\0';
        strVector.push_back(str);
    }
}

void printAnswer(vector<string>& strVector)
{
    for (auto str: strVector) {
        cout << str << " ";
    }
    cout << endl;
}


vector<string> findCombos(int numParenthesis) 
{
    vector<string> stringVector;
    string workString(numParenthesis*2, 'x'); 

    findCombos(0, numParenthesis, workString, 0, stringVector);
    return stringVector;

}


int main()
{
    auto strVector = findCombos(4);
    printAnswer(strVector);
}
