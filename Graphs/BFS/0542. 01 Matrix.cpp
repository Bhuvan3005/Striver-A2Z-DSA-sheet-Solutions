/*
    Problem: 01 Matrix
    Approach: Multi-Source BFS

    Time Complexity  : O(N * M)
    Space Complexity : O(N * M)
*/

class Solution {
    public:
    
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
            int n = mat.size();
            int m = mat[0].size();
    
            vector<vector<int>> ans(n, vector<int>(m, 0));
    
            vector<vector<int>> vis(n, vector<int>(m, -1));
    
            queue<pair<int, pair<int, int>>> q;
    
            // Push All 0s Into Queue
            for (int i = 0; i < n; i++) {
    
                for (int j = 0; j < m; j++) {
    
                    if (mat[i][j] == 0) {
    
                        vis[i][j] = 1;
    
                        q.push({0, {i, j}});
    
                        ans[i][j] = 0;
                    }
                }
            }
    
            int di[4] = {0, 0, 1, -1};
            int dj[4] = {1, -1, 0, 0};
    
            // BFS Traversal
            while (!q.empty()) {
    
                auto node = q.front();
    
                q.pop();
    
                int dist = node.first;
    
                int i = node.second.first;
                int j = node.second.second;
    
                for (int k = 0; k < 4; k++) {
    
                    int newi = i + di[k];
                    int newj = j + dj[k];
    
                    // Boundary Check
                    if (newi < 0 || newj < 0 ||
                        newi >= n || newj >= m) {
                        continue;
                    }
    
                    // Already Visited
                    if (vis[newi][newj] != -1) {
                        continue;
                    }
    
                    vis[newi][newj] = 1;
    
                    ans[newi][newj] = dist + 1;
    
                    q.push({dist + 1, {newi, newj}});
                }
            }
    
            return ans;
        }
    };