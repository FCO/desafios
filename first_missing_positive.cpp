#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unsigned long long acum = 0;

		for (int i : nums)
		{
			if (i > 0)
				acum |= (unsigned long long)1<<(i-1);
		}
		acum = ~acum & (acum+1);
		acum <<= 1;
		acum = log2(acum);
		return acum;
    }
};

int main()
{
	Solution s;
	vector<int> a;
	/*a.push_back(10);
	a.push_back(4);
	a.push_back(16);
	a.push_back(54);
	a.push_back(17);
	a.push_back(-7);
	a.push_back(21);
	a.push_back(15);
	a.push_back(25);
	a.push_back(31);
	a.push_back(61);
	a.push_back(1);
	a.push_back(6);
	a.push_back(12);
	a.push_back(21);
	a.push_back(46);
	a.push_back(16);
	a.push_back(56);
	a.push_back(54);
	a.push_back(12);
	a.push_back(23);
	a.push_back(20);
	a.push_back(38);
	a.push_back(63);
	a.push_back(2);
	a.push_back(27);
	a.push_back(35);
	a.push_back(11);
	a.push_back(13);
	a.push_back(47);
	a.push_back(13);
	a.push_back(11);
	a.push_back(61);
	a.push_back(39);
	a.push_back(0);
	a.push_back(14);
	a.push_back(42);
	a.push_back(8);
	a.push_back(16);
	a.push_back(54);
	a.push_back(50);
	a.push_back(12);
	a.push_back(-10);
	a.push_back(43);
	a.push_back(11);
	a.push_back(-1);
	a.push_back(24);
	a.push_back(38);
	a.push_back(-10);
	a.push_back(13);
	a.push_back(60);
	a.push_back(0);
	a.push_back(44);
	a.push_back(11);
	a.push_back(50);
	a.push_back(33);
	a.push_back(48);
	a.push_back(20);
	a.push_back(31);
	a.push_back(-4);
	a.push_back(2);
	a.push_back(54);
	a.push_back(-6);
	a.push_back(51);
	a.push_back(6);
	*/
	cout << s.firstMissingPositive(a) << endl;
	return 0;
}
