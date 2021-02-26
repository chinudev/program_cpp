#include <vector>
#include <deque>

using namespace std;



// path from 0 to 0,1 or 2 : false
// path from 1 to 0 : true
// path from 1 to 2 : true
// path from 2 to 0 : true

bool findPath(int input[][], int numNodes int source, int dest)
{
    vector <bool> visitVector (numNodes, false);
    deque <int> visitQueue;

    visitQueue.push_back(source);
    visitVector[source]true;

    while (!visitQueue.empty()) {
        int currIndex = visitQueue.pop_front();
        for (int i = 0; i < numNodes; i++) {
            if (input[currIndex][i]) { // if there is a path
                if (visitVector[i] == false) {
                    if (i == dest) return true;
                    visitQueue.push_back(i);
                    visitVector[i] = true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    int input[3][3] = {{0, 0, 0}, 
                       {0, 0, 1},
                       {1, 0, 0}};
    assert(findPath(0,0) == true);
};
