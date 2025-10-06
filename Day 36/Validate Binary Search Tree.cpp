/*
https://leetcode.com/problems/validate-binary-search-tree/solutions/7248743/c-simple-explanation-0ms-runtime-beats-100
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
    vector<int> arr;
    void inorder(TreeNode*root){
        if(!root)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        inorder(root);
        for (int i = 0; i < arr.size()-1; i++)
        {
            if(arr[i]>=arr[i+1])
                return false;
            
        }
        return true;
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

    //brute force approach
    //time complexity: O(n)
    //space complexity: O(n): due to 'arr' and recursive stack(height of tree)

    //to store 'inorder traversal' of tree
    vector<int> arr;

    //function to perfrom 'inorder traversal' of tree
    void inorder(TreeNode* root)
    {   
        //base case: checking for empty node
        if(root==NULL)
            return;

        //recursively traversing 'left' subtree
        inorder(root->left);
        //inserting current node 'value' into arr
        arr.push_back(root->val);
        //recursively traversing 'right' subtree
        inorder(root->right);
    }

    //given function
    bool isValidBST(TreeNode* root)
    {
        //base case: checking for empty tree
        if(root==NULL)
            return true;
        
        //function call to store 'inorder traversal' of given tree in 'arr'
        inorder(root);

        //checking if 'inorder sequence' is strictly increasing
        for(int i=0;i<arr.size()-1;i++)
        {
            //if condition is violated, returning 'false'
            if(arr[i]>=arr[i+1])
                return false;
        }    
        //otherwise, returning 'true' at last
        return true;
    }
};