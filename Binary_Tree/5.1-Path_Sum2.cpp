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
        void dfs(TreeNode* root,int sum,vector<int> &v,vector<vector<int>> &ans){
            if(!root) return;
            //if(sum<0) return;
            v.push_back(root->val);
            sum-=root->val;
            if(sum==0 && root->left==NULL && root->right==NULL) 
            {
                ans.push_back(v);
                v.pop_back();
                return;
            }
    
            dfs(root->left,sum,v,ans);
            dfs(root->right,sum,v,ans);
            v.pop_back();
    
        }
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> ans;
            vector<int> v;
            dfs(root,targetSum,v,ans);
            return ans;
        }
    };