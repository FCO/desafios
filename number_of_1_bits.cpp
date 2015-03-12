/* Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
*
*  For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
		int hw = 0;
        for (int b = 31; b >= 0; --b)
            if ((n >> b) & 1)
                hw++;

        return hw;
    }
};

int main() {
	Solution s;
	cout << s.hammingWeight(11) << endl;
}
