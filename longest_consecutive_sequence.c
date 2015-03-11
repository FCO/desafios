/**************************************************************************************************
URL: https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

***************************************************************************************************/


// BROKEN

#include <stdio.h>

void dump(int vec[]) {
	for(int i = 0; i < 22; i++) printf("[%d]", vec[i]);
	printf("\n");
}

int longestConsecutive(int num[], int n) {
	unsigned char vec[500] = {0}, nvec[500] = {0};
	int bigger_len = 1;
	for(int i = 0; i < n; i++) {
		int p = num[i];
		int len = 1;
		if(p == 0) {
			len += nvec[1] + vec[p + 1];
			vec[p] = len;
		} else if(p < 0) {
			p *= -1;
			len += nvec[p - 1] + nvec[p + 1];
			nvec[p] = len;
		} else {
			len += vec[p - 1] + vec[p + 1];
			vec[p] = len;
		}
		if(len > bigger_len) bigger_len = len;
	}
	return bigger_len;
}

int main() {
	int arr[] = {200, 4, 100, 1, 3, 2};
	printf("-> %d\n", longestConsecutive(arr, 6));
	return 0;
}
