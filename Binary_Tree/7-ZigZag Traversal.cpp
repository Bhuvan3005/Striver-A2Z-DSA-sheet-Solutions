class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if (root == nullptr) return ans;
    
            queue<TreeNode*> q;
            q.push(root);
            bool leftToRight = true;  // use this instead of count
    
            while (!q.empty()) {
                int size = q.size();
                vector<int> level(size);
    
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    // Determine correct index in level vector based on direction
                    int index = leftToRight ? i : size - 1 - i;
                    level[index] = node->val;
    
                    // Standard left-to-right push order
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
    
                ans.push_back(level);
                leftToRight = !leftToRight;  // flip direction for next level
            }
    
            return ans;
        }
    };
    