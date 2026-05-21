class Solution {
    public:
    
        bool f(int i,
               int target,
               vector<int>& nums,
               vector<vector<int>>& dp) {
    
            if(target == 0)
                return true;
    
            if(i == 0)
                return nums[0] == target;
    
            if(dp[i][target] != -1)
                return dp[i][target];
    
            bool notTake = f(i - 1,
                             target,
                             nums,
                             dp);
    
            bool take = false;
    
            if(nums[i] <= target) {
                take = f(i - 1,
                         target - nums[i],
                         nums,
                         dp);
            }
    
            return dp[i][target] = take || notTake;
        }
    
        bool canPartition(vector<int>& nums) {
    
            int n = nums.size();
    
            int sum = accumulate(nums.begin(),
                                 nums.end(),
                                 0);
    
            if(sum & 1)
                return false;
    
            int target = sum / 2;
    
            vector<vector<int>> dp(
                n,
                vector<int>(target + 1, -1)
            );
    
            return f(n - 1,
                     target,
                     nums,
                     dp);
        }
    };






//Tabulated
class Solution {
    public:
    
        bool canPartition(vector<int>& nums) {
    
            int n = nums.size();
    
            int sum = accumulate(nums.begin(),
                                 nums.end(),
                                 0);
    
            if(sum & 1)
                return false;
    
            int target = sum / 2;
    
            vector<vector<bool>> dp(
                n,
                vector<bool>(target + 1, false)
            );
    
            // target 0 always possible
            for(int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
    
            // first element
            if(nums[0] <= target) {
                dp[0][nums[0]] = true;
            }
    
            for(int i = 1; i < n; i++) {
    
                for(int t = 1; t <= target; t++) {
    
                    bool notTake = dp[i - 1][t];
    
                    bool take = false;
    
                    if(nums[i] <= t) {
                        take = dp[i - 1][t - nums[i]];
                    }
    
                    dp[i][t] = take || notTake;
                }
            }
    
            return dp[n - 1][target];
        }
    };


//spaced optimized
class Solution {
    public:
    
        bool canPartition(vector<int>& nums) {
    
            int n = nums.size();
    
            int sum = accumulate(nums.begin(),
                                 nums.end(),
                                 0);
    
            if(sum & 1)
                return false;
    
            int target = sum / 2;
    
            vector<bool> prev(target + 1, false);
            vector<bool> curr(target + 1, false);
    
            prev[0] = true;
    
            if(nums[0] <= target) {
                prev[nums[0]] = true;
            }
    
            for(int i = 1; i < n; i++) {
    
                fill(curr.begin(),
                     curr.end(),
                     false);
    
                curr[0] = true;
    
                for(int t = 1; t <= target; t++) {
    
                    bool notTake = prev[t];
    
                    bool take = false;
    
                    if(nums[i] <= t) {
                        take = prev[t - nums[i]];
                    }
    
                    curr[t] = take || notTake;
                }
    
                prev = curr;
            }
    
            return prev[target];
        }
    };