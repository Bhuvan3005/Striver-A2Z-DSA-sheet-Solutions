class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int s=0;
        int e=n-1;

        int ans=INT_MAX;

        while(s<=e){
            int mid=(s+e)/2;

            if(nums[s]<=nums[mid]){
                ans=min(ans,nums[s]);
                s=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
        }

        return ans;
    }
};


//To find how mant times the array has been rotated..answer is index of min element