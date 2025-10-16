/*
https://leetcode.com/problems/combinations/solutions/1141903/clear-and-simple-explanation-with-intuition-100-faster
*/

class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,int k, vector<int>&current,int n){
        if(current.size()==k){
            ans.push_back(current);
            return;
        }
        for (int i = idx; i < n+1; i++)
        {
            current.push_back(i);
            helper(i + 1, k, current, n);
            current.pop_back();//backtrack
        }
        
    }

    vector<vector<int>> combine(int n, int k) {
            vector<int> current;
            helper(1, k, current, n);
            return ans;
        }
    };