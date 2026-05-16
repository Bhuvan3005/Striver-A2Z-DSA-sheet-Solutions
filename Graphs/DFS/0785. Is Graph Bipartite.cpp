class Solution {
    public:
    
        bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int col){
            vis[node] = col;
    
            for(auto it : graph[node]){
                // same color → not bipartite
                if(vis[it] == col) return false;
    
                // not visited
                if(vis[it] == -1){
                    if(!dfs(it, graph, vis, !col)) return false;
                }
            }
            return true;
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            
            int n = graph.size();
            vector<int> vis(n, -1);
    
            for(int i = 0; i < n; i++){
                if(vis[i] == -1){
                    if(!dfs(i, graph, vis, 0)) return false;
                }
            }
            return true;
        }
    };