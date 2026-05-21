class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>> dp(n,vector(2,0));
    
            
    
            dp[0][0]=0;
            dp[0][1]=-prices[0];
            if(n==1) return 0;
            dp[1][1] = max(-prices[0],-prices[1]);
            
            for(int i=1;i<n;i++){
               if(i>=2) dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
               dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            }
    
            return dp[n-1][0];  
            
        }
    };