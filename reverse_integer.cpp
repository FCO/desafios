/*****************************************************************************
URL: https://leetcode.com/problems/reverse-integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*****************************************************************************/

#include <vector>
#include <stdio.h>

using namespace std;

#define BASE 10
#define MAXINT 2147483647

class Solution
{
public:

    int reverse( int x )
    {

    	int aux = x;
    	double pot = 1;
    	vector<int> reversed;

    	int sign = (x < 0 ? -1 : 1);
    	aux *= sign;

        while( aux )
        {
        	int rest = aux % BASE;
        	reversed.push_back( rest );

        	aux -= rest;
        	aux /= BASE;
        	pot *= BASE;
        }

        double result = 0;
        for(unsigned int i = 0; i < reversed.size(); i++)
        {
        	pot /= BASE;
        	result += reversed[i] * pot;
        }

    	result *= sign;
        if( result > MAXINT || result <= -MAXINT )
        	return 0;

        return (int) result;
    }
};

//***************************************************//
//************ Main for offline testing *************//
//***************************************************//

int main (void)
{
	Solution* solution = new Solution();

	int e1 = solution->reverse( 1534236469 );
	printf( "E1 = %d\n", e1 );
	int e2 = solution->reverse( -2147483412 );
	printf( "E2 = %d\n", e2 );

	return 1;
}
