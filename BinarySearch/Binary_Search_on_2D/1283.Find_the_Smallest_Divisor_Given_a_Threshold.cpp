class Solution {
public:


    int maxelement(vector<int>& nums){
        int maxm=nums[0];
        for(int i=0;i<nums.size();i++){
            maxm=max(maxm,nums[i]);
        }

        return maxm;
    }

    int check(vector<int>& nums,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i] + mid - 1) / mid;
            
        }
        return sum;

    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {

        int s=1;
        int e=maxelement(nums);
        while(s<=e){
            int mid=(s+e)/2;
            
            int total=check(nums,mid);
            
            if(total<=threshold){
                e=mid-1;
                
            }
            else{
                
                s=mid+1;
            }
        }
        return s;

    
        
    }
};