/*
Problem: 540. Single Element in a Sorted Array
Difficulty: Medium

Approach:
- Explicitly handle:
    index 0
    index n-1
- Then apply binary search on remaining range
- Check whether mid itself is the single element
- If mid is odd:
    compare with previous element
- If mid is even:
    compare with next element

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // Only one element
        if(n == 1)
            return nums[0];

        // First element
        if(nums[0] != nums[1])
            return nums[0];

        // Last element
        if(nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int left = 1;
        int right = n - 2;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // Single element found
            if(nums[mid] != nums[mid - 1] &&
               nums[mid] != nums[mid + 1]) {

                return nums[mid];
            }

            // Proper pairing on left side
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
               (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {

                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};