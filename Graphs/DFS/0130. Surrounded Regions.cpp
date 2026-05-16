/*
    Problem: Surrounded Regions
    Approach: DFS from Boundary 'O's

    Time Complexity  : O(N * M)
    Space Complexity : O(N * M)
*/

class Solution {
    public:
    
        void dfs(int i,
                 int j,
                 int n,
                 int m,
                 vector<vector<char>>& board,
                 vector<vector<int>>& vis) {
    
            vis[i][j] = 1;
    
            int di[4] = {0, 1, -1, 0};
            int dj[4] = {1, 0, 0, -1};
    
            // Visit All 4 Directions
            for (int k = 0; k < 4; k++) {
    
                int idi = i + di[k];
                int idj = j + dj[k];
    
                // Boundary Check
                if (idi >= 0 && idi < n &&
                    idj >= 0 && idj < m) {
    
                    if (board[idi][idj] == 'O' &&
                        !vis[idi][idj]) {
    
                        vis[idi][idj] = 1;
    
                        dfs(idi, idj, n, m, board, vis);
                    }
                }
            }
        }
    
        void solve(vector<vector<char>>& board) {
    
            int n = board.size();
            int m = board[0].size();
    
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            // Traverse Boundary Cells
            for (int i = 0; i < n; i++) {
    
                for (int j = 0; j < m; j++) {
    
                    if (i == 0 || i == n - 1 ||
                        j == 0 || j == m - 1) {
    
                        if (board[i][j] == 'O') {
    
                            vis[i][j] = 1;
    
                            dfs(i, j, n, m, board, vis);
                        }
                    }
                }
            }
    
            // Convert Unvisited 'O' to 'X'
            for (int i = 0; i < n; i++) {
    
                for (int j = 0; j < m; j++) {
    
                    if (vis[i][j] == 0 &&
                        board[i][j] == 'O') {
    
                        board[i][j] = 'X';
                    }
                }
            }
        }
    };