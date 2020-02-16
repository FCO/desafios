/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/

    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    You may assume nums1 and nums2 cannot be both empty.

    Example 1:

    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0

    Example 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
*/
class Solution {

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int medianPos = (nums1.length + nums2.length) / 2;
        boolean isEven = (nums1.length + nums2.length) % 2 == 0;

        if(nums1.length == 0) {
            if(isEven) {
                return (nums2[medianPos] + nums2[medianPos-1]) / 2.0;
            } else {
                return nums2[medianPos];
            }
        }
        if(nums2.length == 0) {
            if(isEven) {
                return (nums1[medianPos] + nums1[medianPos-1]) / 2.0;
            } else {
                return nums1[medianPos];
            }
        }

        int pos1 = 0;
        int pos2 = 0;
        int currentValue = 0;
        int lastValue = 0;
        for(int i= 0; i <= medianPos; i++) {

            lastValue = currentValue;
            if(pos1 == nums1.length) {
                currentValue = nums2[pos2];
                pos2++;
            }
            else if(pos2 == nums2.length) {
                currentValue = nums1[pos1];
                pos1++;
            }
            else if(nums1[pos1] > nums2[pos2]) {
                currentValue = nums2[pos2];
                pos2++;
            } else {
                currentValue = nums1[pos1];
                pos1++;
            }
        }

        if(isEven) {
            return (currentValue + lastValue) / 2.0;
        } else {
            return currentValue;
        }

    }
}