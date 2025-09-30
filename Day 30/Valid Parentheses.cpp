/*
https://leetcode.com/problems/valid-parentheses/solutions/7108838/100-beats-0ms-stack-beginner-friendly-python-java-c
*/

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch =='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;

            }
        }
        return st.empty();
    }
};