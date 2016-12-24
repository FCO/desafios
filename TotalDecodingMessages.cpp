/*A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.

Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is length of string N.  1<=N<=40
Second line is string S of digits from '0' to '9' of N length.

Example:
Input:
2
3
123
4
2563

Output:
3
2*/

#include <iostream>
#include <vector>
using namespace std;

int sum (const vector<int>& v){
    int accum = 0;
    for (auto i : v)
        accum += i;
    return accum;
}


int numberOfPossibilities(string s, int n) {
    /* vector<int> count(n+1,0); // A table to store results of subproblems
    
    count[0] = digits[0] != '0'? 1 : 0;
    
    for (int i = 1; i < n; i++){
        if (digits[i] == '0' || digits[i-1] == '0') continue;
        count[i] = 1;
        cout << digits[i] << endl;
        if (digits[i] < '7' && digits[i -1] <= '2') {
            count[i] += 1;
            cout << digits[i] << digits[i-1] << endl;
        }
        
    }
    return sum(count); */
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
    int r1 = 1, r2 = 1;
    
    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}


int main() {
	//code
	int numberOfTest = 0;
	cin >> numberOfTest;
	while (numberOfTest--){
	    string s;
	    int n;
	    cin >> n;
	    cin >> s;
	    cout << numberOfPossibilities(s, s.size()) << endl;
	}
	return 0;
}
