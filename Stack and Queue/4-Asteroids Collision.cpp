class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
    
            int n=asteroids.size();
    
            vector<int> ans;
    
            stack<int> st;
    
            for(int i=0;i<n;i++){
                int num=asteroids[i];
    
                if(num<0){
                    while(!st.empty() && st.top()<abs(num)) st.pop();
                    if(st.empty()) ans.push_back(num);
                    else if(st.top()==abs(num)) st.pop();
    
                }
                else{
                    st.push(num);
                }
            }
    
            vector<int> temp;
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
    
            reverse(temp.begin(),temp.end());
            for(int it:temp) ans.push_back(it);
    
            return ans;
            
        }
    };