/*
    Problem: Rotting Oranges
    Approach: Multi-Source BFS

    Time Complexity  : O(N * M)
    Space Complexity : O(N * M)
*/

class Solution {
    public:
    
        struct orange {
            int i;
            int j;
            int time;
        };
    
        int orangesRotting(vector<vector<int>>& grid) {
    
            int n = grid.size();
            int m = grid[0].size();
    
            int fresh = 0;
    
            queue<orange> q;
    
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            // Push all rotten oranges initially
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
    
                    if (grid[i][j] == 2) {
                        q.push({i, j, 0});
                        vis[i][j] = 1;
                    }
    
                    else if (grid[i][j] == 1) {
                        fresh++;
                    }
                }
            }
    
            int di[] = {1, -1, 0, 0};
            int dj[] = {0, 0, 1, -1};
    
            int maxtime = 0;
    
            // BFS Traversal
            while (!q.empty()) {
    
                int i = q.front().i;
                int j = q.front().j;
                int time = q.front().time;
    
                q.pop();
    
                for (int k = 0; k < 4; k++) {
    
                    int idi = i + di[k];
                    int idj = j + dj[k];
    
                    // Boundary Check
                    if (idi < 0 || idi >= n ||
                        idj < 0 || idj >= m) {
                        continue;
                    }
    
                    // Fresh orange found
                    if (grid[idi][idj] == 1 &&
                        !vis[idi][idj]) {
    
                        q.push({idi, idj, time + 1});
    
                        vis[idi][idj] = 1;
    
                        fresh--;
    
                        maxtime = max(maxtime, time + 1);
                    }
                }
            }
    
            // Fresh oranges still remaining
            if (fresh != 0) {
                return -1;
            }
    
            return maxtime;
        }
    };