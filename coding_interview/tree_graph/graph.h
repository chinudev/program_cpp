
tempatle
// Graph represented using adjacency list
clas GraphNode  
{
public: 
    vector<GraphNode*> 
};


// Graph represented using adjacency matrix
template <typename T, int NumNodes> 
class Graph 
{
public: 
    void read() 
    {
    }

    void print() 
    {
        for (auto i=0; i < NumNodes; i++) {
            cout << i << " : ";
            for (auto j=0; j < NumNodes; j++) {
                cout << Path[i][j] << " ";
            }
            cout << endl;
        }
    }

    T Path[NumNodes][NumNodes];
};


