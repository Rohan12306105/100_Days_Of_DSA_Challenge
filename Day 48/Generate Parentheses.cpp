/*
https://leetcode.com/problems/generate-parentheses/solutions/6048157/video-increase-number-of-open-parentheses-until-we-reach-n-at-first
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;        
    }

private:
    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s);
            return;
        }

        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
};