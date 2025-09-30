/*
https://g.co/gemini/share/4a7be4b7ebed

https://leetcode.com/problems/basic-calculator/solutions/6366727/beats-100-c-python-super-simple-and-efficient-solution-python-c
*/

class Solution {
public:
    int calculate(string s) {
        int ans = 0, num = 0, sign = 1;
        stack<int> stack{{sign}};
        for (const char c: s)
        {
            if(isdigit(c))
                num = num * 10 + (c - '0');
            else if(c=='(')
                stack.push(sign);
            else if(c==')')
                stack.pop();
            else if(c=='+'||c=='-'){
                ans += sign * num;
                sign = (c == '+' ? 1 : -1) * stack.top();
                num = 0;
            }
        }
        return ans + sign * num;
    }
};