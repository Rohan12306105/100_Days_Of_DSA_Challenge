/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/solutions/6965919/beats-100-easiest-explanation-and-code-java-python-c-javascript
*/

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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* node, int path){
        if(!node)
            return 0;
        path = path * 10 + node->val;
        if(!node->left&&!node->right)
            return path;
        return dfs(node->left, path) + dfs(node->right, path);
    }
};