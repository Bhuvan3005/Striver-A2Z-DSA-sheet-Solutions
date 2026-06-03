struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(TreeNode* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}


void levelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }
}

