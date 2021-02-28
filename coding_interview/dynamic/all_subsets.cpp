#include <vector>
#include <iostream>

using namespace std;

//{1,2,3} => {} {1} {2} {3} {1,2} {1,3} {2,3} {1,2,3}
// how do i avoid creating a set and copying it again

vector<vector<int>> createAllSubset(vector<int>& inputSet)
{
    vector<vector<int>> allSubset = {{}};
    for (auto val : inputSet) {
        int currSize = allSubset.size();
        for (int i=0; i < currSize; i++) {
            auto newVec = allSubset[i];
            newVec.push_back(val);
            allSubset.push_back(newVec);
        }
        //cout << val << " = " << allSubset.size() << endl;
    }
    return allSubset;
}

void printResult(vector<vector<int>>& result) 
{
    for (auto vec: result) {
        for (auto val: vec) {
            cout << val << ",";
        }
        cout << endl;
    }
}

int main() 
{
    {
        vector<int> input = {1,2,3};
        vector<vector<int>>expected = {{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}};
        auto output = createAllSubset(input);
        cout << output.size() << endl;
        printResult(output);
    }
}
