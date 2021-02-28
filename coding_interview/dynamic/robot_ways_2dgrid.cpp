#include <vector> 
#include <iostream> 
using namespace std;

// 111
// 123
// 12.


unsigned int findNumPaths(unsigned int X, unsigned int Y)
{
    vector<vector<int>> numPaths (X+1, vector<int>(Y+1,0) );

    numPaths[0][0] = 1;
    for (int x=0; x <=X; x++) {
        for (int y=0; y <=Y; y++) {
            if (numPaths[x][y] > 0) { 
                if ((numPaths[x+1][y] >= 0) && (x < X)) { 
                    numPaths[x+1][y] += numPaths[x][y];
                }
                if ((numPaths[x][y+1] >= 0) && (y < Y)) { 
                    numPaths[x][y+1] += numPaths[x][y];
                }
            }
        }
    }
    return numPaths[X][Y];
}


int main()
{
    cout << findNumPaths(2,2) << endl;
    cout << findNumPaths(0,0) << endl;
    cout << findNumPaths(3,3) << endl;
}
