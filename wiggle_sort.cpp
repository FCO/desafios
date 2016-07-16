/*****************************************************************************
URL: https://leetcode.com/problems/wiggle-sort-ii/

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*****************************************************************************/

#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
    
public:
    
    void wiggleSort(vector<int>& nums)
    {
        // Trivial case
        if(nums.size() == 1)
            return;

        int medianPos = nums.size()/2 + nums.size()%2; 
        // By using median of medians, we guaranty linear run-time
        nth_element(nums.begin(), nums.begin() + medianPos, nums.end());
        int median = nums[medianPos];
    
        // Split array between the median
        unsigned int head = 0;
        unsigned int tail = nums.size()-1;
        for(unsigned int i = 0; i <= tail;)
        {
            if(nums[i] > median)
            {
                swap(nums, i, tail);
                tail--;
            }
            else if(nums[i] < median)
            {
                swap(nums, i, head);
                i++;
                head++;
            }
            else
            {
                i++;
            }
        }

        vector<int> aux(nums.size());
        unsigned int lessTail = (nums.size()-1)/2;
        unsigned int moreTail = nums.size()-1;
        // Left of the median on the odd positions, right of the median of the
        //  even positions
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            if(i%2)
            {
                aux[i] = nums[moreTail];
                moreTail--;
            }
            else
            {
                aux[i] = nums[lessTail];
                lessTail--;
            }
        }

        copy(aux, nums);
        printArray(nums);
    }

private:

    void printArray(vector<int> array)
    {
        printf("[");
        for(unsigned int i = 0; i < array.size(); i++)
        {
            if(i > 0) printf(",");
            printf("%d",array[i]);
        }
        printf("]\n");
    }

    void swap(vector<int>& array, unsigned int a, unsigned int b)
    {
        int aux = array[a];
        array[a] = array[b];
        array[b] = aux;
    }

    void copy(vector<int> from, vector<int>& to)
    {
        for(unsigned int i = 0; i < from.size(); i++)
            to[i] = from[i];
    }
};

//***************************************************//
//************ Main for offline testing *************//
//***************************************************//

int main(void)
{
    Solution* s = new Solution();
    vector<int> test = {1,3,2,2,2,1,1,3,1,1,2};
    s->wiggleSort(test);

    return 1;
}
