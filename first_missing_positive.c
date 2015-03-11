/*****************************************************************************
URL: https://leetcode.com/problems/first-missing-positive/

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*****************************************************************************/

#include <stdio.h>

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		bool res[n];
		int i;
		for(i = 0; i < n; i++) {
			if(A[i] > 0) res[ A[i] - 1 ] = true;
		}
		for(i = 0; i < n; i++) {
			if(!res[i]) return ++i;
		}
		return ++i;
	}
};

int main() {
	Solution *s = new Solution();
	int arr[] = {5,4,2,7,6,1,3};
	printf("-> %d\n", s->firstMissingPositive(arr, 7));
}
