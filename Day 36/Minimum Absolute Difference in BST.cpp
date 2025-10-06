/*
https://leetcode.com/problems/minimum-absolute-difference-in-bst/solutions/7234295/c-simple-explanation-0ms-runtime-beats-100
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
    int ans = INT_MAX;
    int prev = -1;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(prev!=-1){
            int diff = (root->val) - prev;
            ans = min(ans, diff);
        }
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};


// with comments



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
    
    //time complexity: O(n)
    //space complexity: O(h): due to recursive stack

    //global 'ans' variable to store minimum difference
    int ans=INT_MAX;
    //to store value of previous node
    int prevVal=-1;

    //function to perform 'inorder traversal' of given tree
    void inorder(TreeNode* root)
    {
        //base case
        if(root==NULL)
            return;

        //recursively traversing 'left' subtree
        inorder(root->left);

        //checking difference with previous node
        if(prevVal != -1)
        {
            int diff= (root->val) - prevVal;
            //updating 'minimum difference'
            ans=min(ans,diff);
        }
        //updating 'previous' value
        prevVal=(root->val);

        //recursively traversing 'right' subtree
        inorder(root->right);
    }    

    //given function
    int getMinimumDifference(TreeNode* root)
    {
        //function call to get the inorder traversal
        inorder(root);
        return ans;
    }
};