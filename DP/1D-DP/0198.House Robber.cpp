class Solution {
    public:
    
        int f(int i,vector<int> &dp,vector<int> &nums){
    
            if(i<0) return 0;        
            if(dp[i]!=-1) return dp[i];
    
            int pick = nums[i] + f(i - 2, dp, nums);
            int notPick = f(i - 1, dp, nums);
            return dp[i] = max(pick, notPick);
    
            
        }
    
        int rob(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n,-1);
    
            
            return f(n-1,dp,nums);
    
        }
    };

/*TC: O(n)
Each state computed once

SC: O(n) recursion + dp
*/


//Tabulation
class Solution {
    public:
        int rob(vector<int>& nums) {
    
            int n = nums.size();
    
            vector<int> dp(n);
    
            dp[0] = nums[0];
    
            for (int i = 1; i < n; i++) {
    
                int pick = 0;
    
                if (i > 1)
                    pick = nums[i] + dp[i - 2];
    
                int notPick = dp[i - 1];
    
                dp[i] = max(pick, notPick);
            }
    
            return dp[n - 1];
        }
    };

/*TC: O(n)
SC: O(n)
*/


//space optimized
class Solution {
    public:
        int rob(vector<int>& nums) {
    
            int prev2 = 0;
            int prev1 = nums[0];
    
            for (int i = 1; i < nums.size(); i++) {
    
                int pick = nums[i] + prev2;
    
                int notPick = prev1;
    
                int curr = max(pick, notPick);
    
                prev2 = prev1;
                prev1 = curr;
            }
    
            return prev1;
        }
    };

//SC = O(1)