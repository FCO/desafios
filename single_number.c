#include <stdio.h>

int singleNumber(int A[], int n) {

    int acc1=0, acc2=0, i;

    for (i=0; i<n; i++) {
	int acc1_aux = acc1;
        acc1_aux = ((~A[i]) & acc1)|(A[i] & (~acc1) & acc2);
        acc2 = ((~A[i]) & acc2)|(A[i] & (~acc1) & (~acc2));
	acc1 = acc1_aux;
    }

    return acc2;

}

int main(void) {
	int A[] = {1,2,5,6,7,2,1,3,5,1,7,2,6,6,7,5};
	printf("%d\n", singleNumber(A, 16));
}
