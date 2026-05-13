class Solution {


public:


    long long hourly(vector<int>& piles, long long mid){
        long long total=0;      
        
        for(long long i=0;i<piles.size();i++){
                        
            total += ceil((double)piles[i] / mid);
            
        }
        return total;
        
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long s=1;
        long long e=*max_element(piles.begin(),piles.end());


        while(s<=e){
            long long mid=(s+e)/2;
            
            long long total=hourly(piles,mid);
            if(total<=h){                
                e=mid-1;
            }
            else{
                s=mid+1;             
                
            }

        }
        return s;
        
    }
};