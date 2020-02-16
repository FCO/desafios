/*
    https://leetcode.com/problems/trapping-rain-water/

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

    https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png
    The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

    Example:

    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6


*/
class Solution {
    public int trap(int[] height) {

        int j = 0;
        int maxHeight = 0;
        int totalRain = 0;
        for(int i = 0; i < height.length; i++) {

            if (height[i] > maxHeight) {
                for(; j < i; j++) {
                    totalRain += maxHeight - height[j];
                }
                maxHeight = height[i];
            }
        }

        maxHeight = 0;
        for(int i = height.length - 1; i > j; i--) {

            if (height[i] >= maxHeight) {
                maxHeight = height[i];
            }
            totalRain += maxHeight - height[i];
        }

        return totalRain;
     }
}