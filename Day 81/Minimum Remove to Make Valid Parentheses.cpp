/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/solutions/4980313/beats-90easy-stack-and-naive-with-explan-1759
*/

#include <string>
#include <algorithm>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        int open = 0, close = 0, flag = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
                flag++;
            } else if (c == ')' && flag > 0) {
                close++;
                flag--;
            }
        }
        
        int k = std::min(open, close);
        std::string ans = "";
        open = k;
        close = k;
        for (char c : s) {
            if (c == '(') {
                if (open > 0) {
                    ans += '(';
                    open--;
                }
                continue;
            }
            if (c == ')') {
                if (close > 0 && close > open) {
                    ans += ')';
                    close--;
                }
                continue;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};