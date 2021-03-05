#include <iostream> 
#include <vector> 

using namespace std;


void paintFill(vector<vector<int>>& colorGrid, int row, int col, int oldColor, int newColor) 
{
    if (row < 0 || row >= colorGrid.size()) return;
    if (col < 0 || col >= colorGrid[0].size()) return;
    if (colorGrid[row][col] != oldColor) return;

    colorGrid[row][col] = newColor; 

    paintFill(colorGrid, row-1, col-1, oldColor, newColor);
    paintFill(colorGrid, row-1, col,   oldColor, newColor);
    paintFill(colorGrid, row-1, col+1, oldColor, newColor);

    paintFill(colorGrid, row, col-1,  oldColor, newColor);
    paintFill(colorGrid, row, col+1,  oldColor, newColor);

    paintFill(colorGrid, row+1, col-1,  oldColor, newColor);
    paintFill(colorGrid, row+1, col,    oldColor, newColor);
    paintFill(colorGrid, row+1, col+1,  oldColor, newColor);
}

void paintFill(vector<vector<int>>& colorGrid, int row, int col, int newColor) 
{
    if (colorGrid[row][col] == newColor) return; // nothing to do..
    paintFill(colorGrid, row, col, colorGrid[row][col], newColor);
}

int main()
{
}
