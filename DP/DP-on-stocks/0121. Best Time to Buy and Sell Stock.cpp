class Solution {
    public:
        int maxProfit(vector<int>& prices) {
    
            int n=prices.size();
            int pmin=prices[0];
            int pmax=0;
                      
    
            for(int i=1;i<n;i++){
                int sub=prices[i]-pmin;
                pmax=max(pmax,sub);
                pmin=min(prices[i],pmin);
            }
            return pmax;
            
        
            
        }
    };