#include <iostream>

using namespace std;


void nullifyMatrix( int* matrix, int m, int n) 
{
	// Assume we are given a mxn matrix. 
	// For each zero element, set corresponding row and col to all zeros

	int rowFlags[m];   // track which rows need to be set to 0
	for (int i=0; i < m; i++) rowFlags[i]=0;

	int colFlags[n];   // track which columns need to be set to 0
	for (int i=0; i < n; i++) colFlags[i]=0;

	for (int row=0; row < m; row++) {
		for (int col=0; col < n; col++) {
			if (matrix[row*n+col] == 0) {
				rowFlags[row]=1;
				colFlags[col]=1;
			}
		}
	}

	// Set appropriate rows to 0
	for (int row=0; row < m; row++) {
		if (rowFlags[row] == 0) continue;

		for (int col=0; col < n; col++) {
			matrix[row*n+col] = 0;
		}
	}

	// Set appropriate columns to 0
	for (int col=0; col < n; col++) {
		if (colFlags[col] == 0) continue;

		for (int row=0; row < n; row++) {
			matrix[row*n+col] = 0;
		}
	}
}

// print a mxn matrix
void printMatrix(const char* message, int* matrix, int m, int n) 
{
	cout << message << endl;
	for (int row=0; row<m; row++) {
		for (int col=0; col<n; col++) {
			cout << matrix[row*n+col] << "  ";
		}
		cout << endl;
	}
}

void testNullify()
{
	int a[1][1] {{1}};
	printMatrix("input",&a[0][0],1,1);
	nullifyMatrix(&a[0][0],1,1);
	printMatrix("result",&a[0][0],1,1);

	int b[2][1] {{1},{1}};

	printMatrix("input",&b[0][0],2,1);
	nullifyMatrix(&b[0][0],2,1);
	printMatrix("result",&b[0][0],2,1);

	int c[3][3] {{1,1,0},{1,1,0}, {1,1,1}};
	printMatrix("input", &c[0][0],3,3);
	nullifyMatrix(&c[0][0],3,3);
	printMatrix("result",&c[0][0],3,3);
}


/*
 Rotate a square matrix by 90 degrees
*/

void rotateMatrix(int* mat, int maxSize) 
{
	if (mat == nullptr) return;

	for (int i=0; i < int(maxSize/2); i++) {
		int size = maxSize - 2*i;
		int maxI = i+size-1;

		for (int k=0; k < size-1; k++) {
			int tmp = mat[(i)*maxSize + (i + k)];
			/*
			mat[(i)      * maxSize + (i + k) ] = mat[(i+k)    * maxSize + (maxI)  ];
			mat[(i+k)    * maxSize + (maxI)  ] = mat[(maxI)   * maxSize + (maxI-k)];
			mat[(maxI)   * maxSize + (maxI-k)] = mat[(maxI-k) * maxSize + (i)     ];
			mat[(maxI-k) * maxSize + (i)     ] = tmp;
			*/

			mat[(i)      * maxSize + (i + k) ] = mat[(maxI-k) * maxSize + (i)     ];
			mat[(maxI-k) * maxSize + (i)     ] = mat[(maxI)   * maxSize + (maxI-k)];
			mat[(maxI)   * maxSize + (maxI-k)] = mat[(i+k)    * maxSize + (maxI)  ];
			mat[(i+k)    * maxSize + (maxI)  ] = tmp;
		}
	}

}


void testRotate() 
{
	rotateMatrix(nullptr, 0);

	int a[0][0];
	printMatrix("input",&a[0][0], 0,0);
	rotateMatrix(&a[0][0], 0);
	printMatrix("result",&a[0][0], 0,0);

	int b[3][3] {{1,2,3}, {4,5,6}, {7,8,9}};
	printMatrix("input",&b[0][0], 3,3);
	rotateMatrix(&b[0][0], 3);
	printMatrix("result",&b[0][0], 3,3);

	int c[6][6] {{1,2,3,4,5,6}, 
	             {7,8,9,0,1,2}, 
	             {1,2,3,4,5,6}, 
	             {7,8,9,0,1,2}, 
	             {1,2,3,4,5,6}, 
	             {7,8,9,0,1,2}};

	printMatrix("input",&c[0][0], 6,6);
	rotateMatrix(&c[0][0], 6);
	printMatrix("result",&c[0][0], 6,6);

}



int main()
{
	//testNullify();
	testRotate();
}
