/*
-Are duplicates allowed??


Approach:
- Modified Binary Search
- Duplicates make it difficult to identify sorted half
- If nums[left] == nums[mid] == nums[right],
  shrink the search space

Time Complexity: O(log n) average
Worst Case: O(n/2) = O(n)  --->duplicates only shrink by 1 on both sides
Space Complexity: O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
                return true;

            // Handle duplicates
            if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }

            // Left half sorted
            else if(nums[left] <= nums[mid]) {

                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            // Right half sorted
            else {

                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};