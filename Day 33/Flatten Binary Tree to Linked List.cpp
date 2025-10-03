/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/solutions/6907687/beats-100-beginner-friendly-explanation-java-python-c-javascript
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        preorder(root, q);
        if (!q.empty()) q.pop(); // root already used
        while (!q.empty()) {
            root->right = q.front();
            root->left = nullptr;
            q.pop();
            root = root->right;
        }
    }

    void preorder(TreeNode* node, queue<TreeNode*>& q) {
        if (!node) return;
        q.push(node);
        preorder(node->left, q);
        preorder(node->right, q);
    }
};