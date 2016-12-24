/* Given an unsorted array of non-negative integers, find a continous subarray which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.

Note: Position of 1st element of the array should be considered as 1.

Expected Time Complexity: O(n)

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ an array element ≤ 200

Example:

Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5

Explanation : 
In first test case, sum of elements from 2nd position to 4th position is 12
In second test case, sum of elements from 1st position to 5th position is 15

*/

#include <iostream>
#include <vector>
using namespace std;

void subArrayWithGivenSum(const vector<int>& v, int sum) {
    int begin = 0, tail = 0, accum = 0;
    for (tail = 0; tail <= v.size(); ++tail) {
        accum += v[tail];
        while (accum > sum && begin <= tail) {
            accum -= v[begin];
            begin++;
        }
        if (accum == sum) {
            cout << begin + 1 << " " << tail + 1 << endl;
            return;
        }
    }    
    cout << "-1" << endl;
}


int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n, s;
	    cin >> n;
	    cin >> s;
	    
	    vector<int> v;
	    int input;
	    
	    while (n--) {
	        cin >> input;
	        v.push_back(input);
	    }
	    subArrayWithGivenSum(v, s);
	    
	}
	return 0;
}

