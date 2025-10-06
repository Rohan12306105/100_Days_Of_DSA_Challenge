/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/7245847/c-simple-explanation-0ms-runtime-beats-100
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
    int count = 0, ans = -1;
    void inorder(TreeNode*root,int k){
        if(!root)
            return;
        inorder(root->left, k);
        count++;
        if(count==k){
            ans = (root->val);
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};


//with comments


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
    //space complexity: O(h): due to recursive stack(height of tree)

    //to track 'count' of nodes visited
    int count=0;
    //to store final answer
    int ans=-1;

    //function to perform 'inorder traversal'
    void inorder(TreeNode* root, int k)
    {
        //base case: checking for empty tree
        if(root==NULL)
            return;

        //recursively traversing the 'left' subtree
        inorder(root->left,k);

        //increasing the visited nodes count
        count++;
        //checking if current node is 'kth' node visited
        if(count==k)
        {
            //storing node value in 'ans'
            ans=(root->val);
            //stopping further traversal once found
            return;
        }

        //recursively traversing the 'right' subtree
        inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        //function call to perform the 'inorder traversal' of given tree
        inorder(root,k);

        //returning the 'kth smallest' element in given BST
        return ans;    
    }
};