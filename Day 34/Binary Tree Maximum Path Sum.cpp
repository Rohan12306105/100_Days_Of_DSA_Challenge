/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/6601001/video-need-to-understand-what-path-is-exactly
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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode*node,int&res){
        if(!node)
            return 0;
        int leftsum = max(0, dfs(node->left, res));
        int rightsum = max(0, dfs(node->right, res));
        res = max(res, leftsum + rightsum + node->val);
        return max(leftsum, rightsum) + node->val;
    }
};

//with comments

/*
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* node, int& res) {
        if (!node) {
            return 0;
        }

        // Recursively compute the maximum sum of the left and right subtree paths.
        int leftSum = max(0, dfs(node->left, res));
        int rightSum = max(0, dfs(node->right, res));

        // Update the maximum path sum encountered so far (with split).
        res = max(res, leftSum + rightSum + node->val);

        // Return the maximum sum of the path (without split).
        return max(leftSum, rightSum) + node->val;
    }
};

*/