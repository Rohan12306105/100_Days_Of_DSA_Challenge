/*
https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/4279209/beats100-recursive-approach-o-n-step-by-step-explanation
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int count = 0;
        helper(root, count, result);
        return result;
    }
private:
    void helper(TreeNode*root,int count,vector<vector<int>>&result){
        if(!root)
            return;
        if(result.size()<=count){
            result.push_back(vector<int>());
        }
        result[count].push_back(root->val);
        count++;
        helper(root->left, count, result);
        helper(root->right, count, result);
    }
};