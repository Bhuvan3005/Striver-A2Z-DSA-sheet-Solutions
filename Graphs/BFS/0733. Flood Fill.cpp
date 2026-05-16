/*
    Problem: Flood Fill
    Approach: DFS Traversal

    Time Complexity  : O(N * M)
    Space Complexity : O(N * M)
*/

class Solution {
    public:
    
        void dfs(vector<vector<int>>& image,
                 int i,
                 int j,
                 int color,
                 int originalColor) {
    
            // Boundary + Color Check
            if (i < 0 || j < 0 ||
                i >= image.size() ||
                j >= image[0].size() ||
                image[i][j] != originalColor) {
    
                return;
            }
    
            // Fill Current Cell
            image[i][j] = color;
    
            int di[] = {0, -1, 0, 1};
            int dj[] = {-1, 0, 1, 0};
    
            // Visit All 4 Directions
            for (int k = 0; k < 4; k++) {
    
                int idk = i + di[k];
                int jdk = j + dj[k];
    
                dfs(image, idk, jdk, color, originalColor);
            }
        }
    
        vector<vector<int>> floodFill(vector<vector<int>>& image,
                                      int sr,
                                      int sc,
                                      int color) {
    
            int originalColor = image[sr][sc];
    
            // No Need to Fill Again
            if (originalColor == color) {
                return image;
            }
    
            dfs(image, sr, sc, color, originalColor);
    
            return image;
        }
    };