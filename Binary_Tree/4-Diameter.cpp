/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        int diameter(TreeNode* root, int &maxDiameter) {
            if (root == NULL) return 0;
    
            int lh = diameter(root->left, maxDiameter);
            int rh = diameter(root->right, maxDiameter);
    
            maxDiameter = max(maxDiameter, lh + rh);
    
            return 1 + max(lh, rh);
        }
    
        int diameterOfBinaryTree(TreeNode* root) {
            int maxDiameter = 0;
            diameter(root, maxDiameter);
            return maxDiameter;
        }
    };
    