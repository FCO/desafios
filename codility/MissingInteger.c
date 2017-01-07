/*

Codility Lesson 04
==================

https://codility.com/programmers/lessons/4-counting_elements/

Current Score: 100%

Description
===========

Write a function:

int solution(int A[], int N);

that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.

For example, given:

  A[0] = 1
  A[1] = 3
  A[2] = 6
  A[3] = 4
  A[4] = 1
  A[5] = 2
the function should return 5.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

*/

int solution(int A[], int N) {
         
    // populate R with zeros
    int R[N];
    for(int i = 0; i < N; i++)
        R[i] = 0;
    
    // populate array with existing numbers
    for(int i = 0; i < N; i++)
    {
        if(A[i] <= N && A[i] >= 1)
            R[A[i]-1] = 1;
    }
    
    // search for missing number, i.e. the first zero
    for(int i = 0; i < N; i++)
        if(!R[i]) return i + 1;
            
    return N+1;
}