/*
    Problem: Number of Enclaves
    Approach: DFS from Boundary Land Cells

    Time Complexity  : O(N * M)
    Space Complexity : O(N * M)
*/

class Solution {
    public:
    
        void dfs(int i,
                 int j,
                 int n,
                 int m,
                 vector<vector<int>>& vis,
                 vector<vector<int>>& grid) {
    
            vis[i][j] = 1;
    
            int di[4] = {0, 1, -1, 0};
            int dj[4] = {1, 0, 0, -1};
    
            // Visit All 4 Directions
            for (int k = 0; k < 4; k++) {
    
                int new_i = i + di[k];
                int new_j = j + dj[k];
    
                // Boundary Check
                if (new_i >= 0 && new_i < n &&
                    new_j >= 0 && new_j < m) {
    
                    if (!vis[new_i][new_j] &&
                        grid[new_i][new_j] == 1) {
    
                        dfs(new_i, new_j, n, m, vis, grid);
                    }
                }
            }
        }
    
        int numEnclaves(vector<vector<int>>& grid) {
    
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            // Traverse Boundary Cells
            for (int i = 0; i < n; i++) {
    
                for (int j = 0; j < m; j++) {
    
                    if (i == 0 || i == n - 1 ||
                        j == 0 || j == m - 1) {
    
                        if (grid[i][j] == 1) {
    
                            vis[i][j] = 1;
    
                            dfs(i, j, n, m, vis, grid);
                        }
                    }
                }
            }
    
            int count = 0;
    
            // Count Unvisited Land Cells
            for (int i = 0; i < n; i++) {
    
                for (int j = 0; j < m; j++) {
    
                    if (grid[i][j] == 1 &&
                        vis[i][j] == 0) {
    
                        count++;
                    }
                }
            }
    
            return count;
        }
    };