//Handle leading zeroes
//if remaining k after operation..remove elemnts..u have to make k=0

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        int n=num.size();



        for(int i=0;i<n;i++){
            int nums=num[i]-'0';
            while(!st.empty() && st.top()>nums && k){
                st.pop();
                k--;
            }
            st.push(nums);
        }

        while(!st.empty() && k){
            st.pop();
            k--;
        }

        string ans="";

        while(!st.empty()){
            ans+=(st.top()+'0');
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int n1=ans.size();

        int i=0;
        while(i<n1 && ans[i]=='0') i++;
        
        if(i==n1) return "0";
        else return ans.substr(i,n1-i);
    }
};