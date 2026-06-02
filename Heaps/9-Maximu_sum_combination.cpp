class Solution {
    public:
        vector<int> solve(vector<int>& A, vector<int>& B, int K) {
    
            int n = A.size();
    
            sort(A.begin(), A.end(), greater<int>());
            sort(B.begin(), B.end(), greater<int>());
    
            priority_queue<vector<int>> pq;
    
            set<pair<int,int>> vis;
    
            pq.push({A[0] + B[0], 0, 0});
            vis.insert({0,0});
    
            vector<int> ans;
    
            while(K--) {
    
                auto cur = pq.top();
                pq.pop();
    
                int sum = cur[0];
                int i = cur[1];
                int j = cur[2];
    
                ans.push_back(sum);
    
                if(i + 1 < n && !vis.count({i+1,j})) {
                    pq.push({A[i+1] + B[j], i+1, j});
                    vis.insert({i+1,j});
                }
    
                if(j + 1 < n && !vis.count({i,j+1})) {
                    pq.push({A[i] + B[j+1], i, j+1});
                    vis.insert({i,j+1});
                }
            }
    
            return ans;
        }
    };