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
        bool check(TreeNode* p, TreeNode* q){
            if (!p) return q==NULL;
            if(!q) return p==NULL;
    
            bool a=check(p->left,q->left);
            bool b=check(p->right,q->right);
    
            return p->val==q->val& a&b;
    
        }
        bool isSameTree(TreeNode* p, TreeNode* q) {
            return check(p,q);
        }
    };