/*
https://leetcode.com/problems/path-sum/solutions/3977919/easy-solution-python3-c-c-c-java-explain-line-by-line-with-image

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
    bool hasPathSum(TreeNode* root, int targetsum) {
        if(!root)
            return false;
        if(!root->left&&!root->right){
            return targetsum == root->val;
        }
        return hasPathSum(root->left, targetsum - root->val) || hasPathSum(root->right, targetsum - root->val);
    }
};

/*
Here's how the solution works:

If root is None (i.e., the tree is empty), there can't be any path with the desired sum. So, the function returns False.

If root is a leaf node (i.e., it has no left or right children), the function checks whether the value of the leaf node is equal to the remaining targetSum. If they are equal, it returns True, indicating that a valid path with the target sum has been found.

If the above conditions are not met, the function recursively checks for a valid path with the target sum in both the left and right subtrees. It subtracts the value of the current node from the targetSum before passing it to the recursive calls.

The result of the recursive calls on the left and right subtrees (left_sum and right_sum) are then combined using the logical OR operation. This is because if either the left subtree or the right subtree has a valid path, it means there's a valid path in the entire tree, so the function should return True.

If none of the above conditions are met, the function returns False.

*/