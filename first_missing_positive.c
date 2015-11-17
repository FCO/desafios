/*****************************************************************************
URL: https://leetcode.com/problems/first-missing-positive/

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*****************************************************************************/

#include <stdio.h>

int firstMissingPositive(int* A, int n) {
	char res[n];
	for(int j = 0; j < n; j++) res[j]=0;
	int i;
	if(n < 1) return 1;
	for(i = 0; i < n; i++) {
		if(A[i] > 0 && A[i] <= n) res[ A[i] - 1 ] = 1;
	}
	for(i = 0; i < n; i++) {
		if(!res[i]) return ++i;
	}
	return ++i;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	printf("-> %d\n", firstMissingPositive(arr, 5));
}
