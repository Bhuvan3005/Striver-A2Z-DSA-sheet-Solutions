/*
    Problem: Number of Provinces
    Approach: DFS on Graph

    Time Complexity  : O(V + E)
    Space Complexity : O(V + E)
*/

class Solution {
    public:
    
        void dfs(int node,
                 vector<vector<int>>& adj,
                 vector<int>& vis) {
    
            vis[node] = 1;
    
            for (int neighbour : adj[node]) {
                if (!vis[neighbour]) {
                    dfs(neighbour, adj, vis);
                }
            }
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
    
            int n = isConnected.size();
    
            // Adjacency List
            vector<vector<int>> adj(n);
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
    
                    if (i != j && isConnected[i][j] == 1) {
                        adj[i].push_back(j);
                    }
                }
            }
    
            vector<int> vis(n, 0);
    
            int provinces = 0;
    
            // Count Connected Components
            for (int i = 0; i < n; i++) {
    
                if (!vis[i]) {
                    dfs(i, adj, vis);
                    provinces++;
                }
            }
    
            return provinces;
        }
    };