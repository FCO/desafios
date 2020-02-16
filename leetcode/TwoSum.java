/*
    https://leetcode.com/problems/two-sum/

    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

        Given nums = [2, 7, 11, 15], target = 9,

        Because nums[0] + nums[1] = 2 + 7 = 9,
        return [0, 1].
*/

class Solution {

    // Solution optimizating execution time while spending more memory
    public int[] twoSum(int[] nums, int target) {

        Map<Integer,Integer> map = new HashMap();
        for(int i = 0; i < nums.length; i++) {
            if(map.containsKey(nums[i]) && (nums[i]*2 == target)) {
                return new int[]{map.get(nums[i]), i};
            }
            map.put(nums[i], i);
        }
        for(Integer num : map.keySet()) {
            int diff = target - num;
            if(map.containsKey(diff)) {
                return new int[]{map.get(num), map.get(diff)};
            }
        }
        return null;
    }
}