//Brute force..create lmax rmax array at iterate

class Solution {
    public:
        int trap(vector<int>& height) {
            int n=height.size();
            int i=0;
            int j=n-1;
            
    
            int left_max=height[0];
            int right_max=height[n-1];
            int ans=0;
    
            while(i<=j){
                left_max=max(left_max,height[i]);
                right_max=max(right_max,height[j]);
    
                if(left_max<right_max){   //left boundary set for i
                    ans+=left_max-height[i];
                    i++;
                }
                else{
                    ans+=right_max-height[j];
                    j--;
                }
            }
    
            return ans;
        }
    };