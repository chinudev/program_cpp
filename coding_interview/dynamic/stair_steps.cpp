#include <vector>
#include <iostream> 

using namespace std;

int findWaysToClimb(unsigned int steps) 
{
    vector<int> stepsTaken = {1,2,3};   // Number of steps that can be taken
    
    vector<int> numWays(steps+1,0);  // Track number of ways to reach a step
    numWays[0] = 1;

    for (auto i=0; i <=steps; i++) {
        //cout << "On step " << i << endl;
        for (auto step: stepsTaken) {
            //cout << "   step size = " << step << endl;
            if (step + i <= steps) {  // Don't count beyond numWays[steps]
                numWays[step+i] = numWays[step+i] + numWays[i];
                //cout <<  "      " << step+i << " = " << numWays[step+i] << endl;
            }
        }
    }
    return numWays[steps];
}


int main()
{
    assert(findWaysToClimb(1) == 1);
    assert(findWaysToClimb(2) == 2);
    cout << findWaysToClimb(5) << endl;
}


