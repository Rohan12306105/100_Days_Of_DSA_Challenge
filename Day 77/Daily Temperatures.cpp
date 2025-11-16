/*
https://leetcode.com/problems/daily-temperatures/solutions/4651723/easy-stack-friendly-explained-by-prodoni-dlpa
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int>result(temps.size());
        stack<int>stack;
        for (int i = 0; i < temps.size(); i++)
        {
            while(!stack.empty()&&temps[stack.top()]<temps[i]){
                result[stack.top()]=i-stack.top();
                stack.pop();
            }stack.push(i);
        }return result;
        
    }
};