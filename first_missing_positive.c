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
