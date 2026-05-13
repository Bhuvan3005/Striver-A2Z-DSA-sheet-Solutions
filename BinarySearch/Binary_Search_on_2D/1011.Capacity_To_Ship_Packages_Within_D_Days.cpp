class Solution {
public:

    bool check(vector<int>& weights, int days,int mid){
        int sum=0;
        int count=1;

        for (int it : weights) {
            if (it > mid) return false; 

            if (sum + it > mid) {
                count++;
                sum = it;
            } else {
                sum += it;
            }
        }

        return count<=days;

    }




    int shipWithinDays(vector<int>& weights, int days) {

        int s=1;
        int e=500*size(weights);
        

        while(s<=e){
            int mid=(s+e)/2;
            if(check(weights,days,mid)){
               
                e=mid-1;
            }
            else{
                s=mid+1;
            }


        }

        return s;

        
    }
};