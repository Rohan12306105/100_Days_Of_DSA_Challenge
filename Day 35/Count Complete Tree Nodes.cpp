/*
https://leetcode.com/problems/count-complete-tree-nodes/solutions/6883960/easy-to-understand-beginner-friendly-easy-solution
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
    int leftheight(TreeNode*root){
        TreeNode *temp = root;int h=0;
        while(temp){
            temp = temp->left;
            h++;
        }
        return h;
    }
    int rightheight(TreeNode*root){
        TreeNode *temp = root;int h=0;
        while(temp){
            temp = temp->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(lh==rh)
            return pow(2, lh) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};