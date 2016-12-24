/*Print the resultant string after adding given two binary strings

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains two binary strings s1 and s2 separated by space.


Output:
For each test case print the resultant binary string.

Constraints:

1<=T<=70

1<=|s1|,|s2|<=200, where |s| represents the length of string s


Example:

Input:

2
1101 111
10 01

Output:

10100
11 */

#include <iostream>
using namespace std;

string lpad(string s, int pad) {
    string newS(s.size() + pad, '0');
    for (int i = 0; i < s.size(); i++) {
        newS[i+pad] = s[i];
    }
    
    //cout << s << endl << newS << endl;
    return newS;
}

void sameSize(string& s1, string& s2) {
    int pad = abs((int)(s1.size() - s2.size()));
    if (s1.size() < s2.size())
        s1 = lpad(s1, pad);
    else
        s2 = lpad(s2, pad);
        
    //cout << "s1= " << s1 << endl << "s2= " << s2 << endl;
	    
}

string sumBinaryStrings(string& n1, string& n2) {
    string result;
    if (n1.size() != n2.size()) sameSize(n1, n2);
    
    bool carry = false;
    for (int i = n1.size() -1; i >= 0; --i) {
        if (n1[i] == '1' && n2[i] == '1') {
            if (!carry) {
                carry = true;
                result.push_back('0');
            } else {
                carry = true;
                result.push_back('1');
            }
        }
        if (n1[i] == '0' && n2[i] == '0') {
            if (!carry) {
                result.push_back('0');
            } else {
                carry = false;
                result.push_back('1');
            }
        }
        if (n1[i] == '1' && n2[i] == '0') {
            if (!carry) {
                result.push_back('1');
            } else {
                carry = true;
                result.push_back('0');
            }
        }
        if (n1[i] == '0' && n2[i] == '1') {
            if (!carry) {
                result.push_back('1');
            } else {
                carry = true;
                result.push_back('0');
            }
        }
    }
    if (carry) result.push_back ('1');
    string reversed(result.rbegin(), result.rend());
    
    if (result.size() < n1.size()) cout << "fu" << endl;
    return reversed;
}

int main() {
	//code
	int test = 0;
	cin >> test;
	while (test--) {
	    string n1, n2;
	    cin >> n1;
	    cin >> n2;
	    
	    //cout << "n1= " << n1 << endl << "n2= " << n2 << endl;
	    cout << sumBinaryStrings(n1, n2) << endl;
	}
	return 0;
} 
