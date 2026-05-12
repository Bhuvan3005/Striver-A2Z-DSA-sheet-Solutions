/*
Problem: 162. Find Peak Element
Difficulty: Medium

Approach:
-Trim search space
- Explicitly check whether mid is peak
- If left neighbor is greater(decreasing slope),
  move left
- Else move right (increasing slope or dip) it is guaranteed to havepeak on right


Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        // Single element
        if(n == 1)
            return 0;

        // First element
        if(nums[0] > nums[1])
            return 0;

        // Last element
        if(nums[n - 1] > nums[n - 2])
            return n - 1;

        int left = 1;
        int right = n - 2;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // Peak element found
            if(nums[mid] > nums[mid - 1] &&
               nums[mid] > nums[mid + 1]) {

                return mid;
            }

            // Move left
            if(nums[mid - 1] > nums[mid])
                right = mid - 1;

            // Move right
            else
                left = mid + 1;
        }

        return -1;
    }
};