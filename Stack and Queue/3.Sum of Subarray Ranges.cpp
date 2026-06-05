// m(a)-n(a)   m maximum contri , n minimum contri of a in subarrays

using vi = vector<int>;

class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n=nums.size();
        
        vi psee(n,-1);
        vi nse(n,n);
        vi pgee(n,-1);
        vi nge(n,n);

        stack<int> st;

        //--------psse------------------------
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(!st.empty()) psee[i]=st.top();

            st.push(i);
        }

        //---------pgee-------------
        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) pgee[i]=st.top();

            st.push(i);
        }


        //--------------nge---------

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) nge[i]=st.top();

            st.push(i);
        }

        //--------------nse------

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();

            st.push(i);
        }


        //---------------------------------

        long long ans=0;

        for(int i=0;i<n;i++){
            int min1=i-psee[i];
            int min2=nse[i]-i;

            long long ans1=1LL*min1*min2*nums[i];

            int max1=i-pgee[i];
            int max2=nge[i]-i;

            long long ans2=1LL*max1*max2*nums[i];

            ans+=ans2-ans1;
        }

        return ans;







        
    }
};