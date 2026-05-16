/*
    Problem: Detect Cycle in an Undirected Graph
    Approach: DFS with Parent Tracking

    Time Complexity  : O(V + E)
    Space Complexity : O(V)
*/

class Solution {
    public:
    
        bool dfs(int node,
                 int parent,
                 vector<int> adj[],
                 vector<int>& vis) {
    
            vis[node] = 1;
    
            for (int neigh : adj[node]) {
    
                // Unvisited Neighbour
                if (!vis[neigh]) {
    
                    if (dfs(neigh, node, adj, vis)) {
                        return true;
                    }
                }
    
                // Visited Neighbour Other Than Parent
                else if (neigh != parent) {
                    return true;
                }
            }
    
            return false;
        }
    
        bool isCycle(int V, vector<int> adj[]) {
    
            vector<int> vis(V, 0);
    
            // Check Every Connected Component
            for (int i = 0; i < V; i++) {
    
                if (!vis[i]) {
    
                    if (dfs(i, -1, adj, vis)) {
                        return true;
                    }
                }
            }
    
            return false;
        }
    };