/*
    Problem: Number of Islands
    Approach: DFS Traversal

    Time Complexity  : O(N * M)
    Space Complexity : O(N * M)
*/

class Solution {
    public:
    
        bool isValid(int i,
                     int j,
                     int n,
                     int m) {
    
            return i >= 0 &&
                   j >= 0 &&
                   i < n &&
                   j < m;
        }
    
        void dfs(vector<vector<char>>& grid,
                 vector<vector<int>>& vis,
                 int i,
                 int j,
                 int n,
                 int m) {
    
            vis[i][j] = 1;
    
            int di[4] = {0, 1, -1, 0};
            int dj[4] = {1, 0, 0, -1};
    
            // Visit All 4 Directions
            for (int k = 0; k < 4; k++) {
    
                int new_i = i + di[k];
                int new_j = j + dj[k];
    
                if (isValid(new_i, new_j, n, m)) {
    
                    if (!vis[new_i][new_j] &&
                        grid[new_i][new_j] == '1') {
    
                        dfs(grid, vis, new_i, new_j, n, m);
                    }
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
    
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            int count = 0;
    
            // Traverse Entire Grid
            for (int i = 0; i < n; i++) {
    
                for (int j = 0; j < m; j++) {
    
                    if (!vis[i][j] &&
                        grid[i][j] == '1') {
    
                        count++;
    
                        dfs(grid, vis, i, j, n, m);
                    }
                }
            }
    
            return count;
        }
    };