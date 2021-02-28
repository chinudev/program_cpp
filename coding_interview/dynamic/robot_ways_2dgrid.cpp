#include <array> 
#include <iostream> 
using namespace std;

// 111
// 123
// 12.

template <typename T, int Rows, int Cols>
auto makeArray2D() 
{
    std::array< std::array<T, Cols>, Rows> 2dArray;
    return 2dArray;
}


unsigned int findNumPaths(unsigned int X, unsigned int Y)
{
    std::array< std::array<int, X+1>, Y+1> numPaths; 
    vector< vector<int>> (

    numPaths[0][0] = 1;
    for (int x=0; x <=X; x++) {
        for (int y=0; y <=Y; y++) {
            if (x < X) numPaths[x+1][y] += numPaths[x][y];
            if (y < Y) numPaths[x][y+1] += numPaths[x][y];
        }
    }
    return numPaths[X][Y];
}


int main()
{
    cout << numPaths(2,2) << endl;
    cout << numPaths(0,0) << endl;
    cout << numPaths(3,3) << endl;
}
