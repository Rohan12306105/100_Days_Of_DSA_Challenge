
/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/1770060/c-recursive-dfs-example-dry-run-well-explained
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
    int maxDepth(TreeNode* root) {
        //base case
        if(!root){
            return 0;
        }
        // recur rltn
        int lef_max = maxDepth(root->left);
        int righ_max = maxDepth(root->right);
        return max(lef_max, righ_max)+1;
    }
};