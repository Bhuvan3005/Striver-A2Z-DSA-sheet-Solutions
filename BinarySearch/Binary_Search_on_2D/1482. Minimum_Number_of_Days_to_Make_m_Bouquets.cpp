class Solution {
public:

    bool check(vector<int>& bloomDay,int mid,int m,int k){

        int cumilative=0;
        int total=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cumilative++;
                if(cumilative==k){
                    total++;
                    cumilative=0;

                }
                
                
            }
            else{
                cumilative=0;
            }
            

        }
        return total>=m;


    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        
        int s=1;
        int e=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        if(1LL * m * k > bloomDay.size()) return -1;

        while(s<=e){
            int mid=(s+e)/2;
            if(check(bloomDay,mid,m,k)){
                
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;



        
    }
};