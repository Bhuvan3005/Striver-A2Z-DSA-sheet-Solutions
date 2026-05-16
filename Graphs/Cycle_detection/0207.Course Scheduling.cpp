/*
    Problem: Course Schedule
    Approach: Kahn's Algorithm (Topological Sort using BFS)

    Time Complexity  : O(V + E)
    Space Complexity : O(V + E)
*/

class Solution {
    public:
    
        bool canFinish(int numCourses,
                       vector<vector<int>>& prerequisites) {
    
            vector<int> indegree(numCourses, 0);
    
            vector<int> adj[numCourses];
    
            queue<int> q;
    
            vector<int> topo;
    
            // Build Graph
            for (auto it : prerequisites) {
    
                adj[it[1]].push_back(it[0]);
    
                indegree[it[0]]++;
            }
    
            // Push Nodes with Indegree 0
            for (int i = 0; i < numCourses; i++) {
    
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            // BFS Traversal
            while (!q.empty()) {
    
                int node = q.front();
    
                q.pop();
    
                topo.push_back(node);
    
                for (auto it : adj[node]) {
    
                    indegree[it]--;
    
                    if (indegree[it] == 0) {
                        q.push(it);
                    }
                }
            }
    
            // If Topological Sort Contains All Nodes
            return topo.size() == numCourses;
        }
    };