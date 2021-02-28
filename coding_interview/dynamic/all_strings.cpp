#include <vector>
#include <string>
#include <map>
#include <iostream> 

using namespace std;

// bac -> bac, bca, abc, acb, cab, cba
// Two ways to proceed 
  // Option 1
  // a -> ab ba -> cab acb abc, cba bca bac
  // At each step add a new letter and insert in all locations. 

  // Option 2: chosen
  // a b c -> ab ac ba bc ca cb ->.. 
  // At each stage recruse and tell the next function what char are remaining

void print(vector<string>& strVector) 
{
    for (auto str: strVector) {
        cout << str << " : ";
    }
    cout << endl;
}

vector<string> allPermutations(map<string, bool>& charMap)
{
    vector<string> resultVector;

    for (auto [chr, present] : charMap) {
        if (present == true) {
            charMap[chr] = false;
            for (auto substr : allPermutations(charMap) ) {
                string s(chr); 
                s += substr;
                resultVector.push_back(s);
            }
            charMap[chr] = true;
        }
    }
    if (resultVector.size() == 0) resultVector.push_back(string(""));
    return resultVector;
}

vector<string> allPermutations(const string& str)
{
    map<string, bool> charMap; 
    for (auto chr: str) {
        string str; str.push_back(chr);
        if (charMap[str] == true) {
            // duplicate entries should not happen
            cout << "Unexpected input: duplicate in string " << endl;
            return {};
        }
        charMap[str] = true;
    }

    return allPermutations(charMap);
}



int main()
{
    {
        auto strVector = allPermutations(string("abc"));
        print(strVector);
    }
    {
        auto strVector = allPermutations(string("dacb"));
        print(strVector);
    }
}


