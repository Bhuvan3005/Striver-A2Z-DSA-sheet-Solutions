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
        int f(TreeNode* root){
            if(root==NULL) return 0;
    
            int a=f(root->left);
            int b=f(root->right);
    
            return 1+max(a,b);
        }
        int maxDepth(TreeNode* root) {
            
            return f(root);
        }
    };