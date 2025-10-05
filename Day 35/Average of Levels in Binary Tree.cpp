/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/solutions/6894465/using-bfs-easiest-solution-and-code-java-python-c-javascript
*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(sum / size);
        }

        return res;
    }
};