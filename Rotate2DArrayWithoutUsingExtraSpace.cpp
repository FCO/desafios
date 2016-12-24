/*You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is 

1 2 3 4 5 6 7 8 9

Then the rotated array becomes: 

7 4 1 8 5 2 9 6 3

Input:

The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains an integer 'N' denoting the size of the 2D square matrix.

And in the second line, the elements of the matrix A[][], each separated by a space in row major form.


Output:

For each test case, print the elements of the rotated array row wise, each element separated by a space. Print the output of each test case in a new line.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 10
1 ≤ A [ i ][ j ] ≤ 100


Example:

Input:

2
3
1 2 3 4 5 6 7 8 9
2
56 96 91 54

Output:

7 4 1 8 5 2 9 6 3
91 56 54 96
*/


#include <iostream>
#include <vector>

using namespace std;

void printRotatedMatrix(const vector<vector<int>>& m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << m[i][j];
            if (i != n - 1 || j != n - 1) cout << " ";
        }
    }
    cout << endl;
}


void rotateMatrix(vector<vector<int>>& m, int n, int layer) {
    if (n <= 1) return;
    
    for (int i = 0; i < n -1; i++){
        int aux = m[layer][layer + i];
        
        //cout << "m["<<layer<<"]["<<layer + i<<"] = m[" << n -1 + layer - i<<"]["<<layer<<"]" << endl;
        m[layer][layer + i] = m[n -1 + layer - i][layer];
        
        int aux2 = m[layer + i][n - 1 + layer];
        
        //cout << "m["<<layer + i<<"]["<<n - 1 + layer<<"] = m["<<layer<<"]["<<layer + i<<"]"<< endl;
        m[layer + i][n - 1 + layer] = aux;
        aux = m[n - 1 + layer][n - 1 + layer -i];
        
        //cout<<"m["<<n - 1 + layer<<"]["<<n - 1 + layer -i<<"] = m["<<layer + i<<"]["<<n - 1 + layer<<"]" << endl;
        m[n - 1 + layer][n - 1 + layer - i] = aux2;
        
        //cout<<"m["<<n -1 + layer - i<<"]["<<layer<<"] = m["<<n - 1 + layer<<"]["<<n - 1 + layer -i<<"]"<<endl;
        m[n -1 + layer - i][layer] = aux;
    }
    
    rotateMatrix(m, n - 2, ++layer);
}

int main() {
	//code
	int test = 0;
	cin >> test;
	while (test--) {
	    int n;
	    cin >> n;
	    vector<vector<int>> m(n, vector<int>(n, 0));
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cin >> m[i][j];
	        }
	    }
	 
	    rotateMatrix(m, n, 0);
	    printRotatedMatrix(m, n);
	    
	}
	return 0;
}
 
