/*
https://leetcode.com/problems/longest-happy-prefix/solutions/6586824/easy-beginner-friendly-beats-100-notes-j-97dh
*/

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> dp(s.size(), 0);
        int len = 0, i = 1;
        while (i < s.size()) {
            if (s[i] == s[len]) {
                dp[i] = ++len;
                i++;
            } else {
                if (len > 0) {
                    len = dp[len - 1];
                } else {
                    dp[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, dp.back());
    }
};

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lpsLength(s.length(), 0);
        int len = 0;
        int j = 1;
        
        while (j < s.length()) {
            if (s[j] == s[len]) {
                len++;
                lpsLength[j] = len;
                j++;
            } else {
                if (len > 0) {
                    len = lpsLength[len - 1];
                } else {
                    lpsLength[j] = 0;
                    j++;
                }
            }
        }
        
        return s.substr(0, lpsLength[s.size() - 1]);
    }
};