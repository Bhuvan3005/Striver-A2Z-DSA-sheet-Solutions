class Solution {
    public:
    
        vector<int> psse(vector<int> &vector_psse,stack<int> &st,vector<int> heights){
    
            for(int i=0;i<heights.size();i++){
                while(!st.empty() && heights[st.top()]>heights[i]){
                    st.pop();
                }
                if(!st.empty()) vector_psse[i]=st.top();
                st.push(i);
            }
            return vector_psse;
    
    
        }
    
    
        vector<int> nse(vector<int> &vector_nse,stack<int> &st2,vector<int> heights){
    
            for(int i=heights.size()-1;i>=0;i--){
                while(!st2.empty() && heights[st2.top()]>=heights[i]){
                    st2.pop();
                }
                if(!st2.empty()) vector_nse[i]=st2.top();
                st2.push(i);
            }
            return vector_nse;
    
    
        }
    
    
        int largestRectangleArea(vector<int>& heights) {
    
            stack<int> st;
            stack<int> st2;
            vector<int> vector_psse(heights.size(),-1);
            vector<int> vector_nse(heights.size(),heights.size());
            psse(vector_psse,st,heights);
            nse(vector_nse,st2,heights);
    
            
    
            int maxArea=0;
            for(int i=0;i<heights.size();i++){
    
                int width = vector_nse[i] - vector_psse[i] - 1;
                int area = heights[i] * width;
                maxArea = max(maxArea, area);
            }
    
            return maxArea;
    
    
            
        }
    };