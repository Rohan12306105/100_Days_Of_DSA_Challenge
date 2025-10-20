/*
this will ive TLE , so use memoization

// same as fibonacci


class Solution {
public:
    int climbStairs(int n) {
        if(n>1){
            return climbStairs(n-1)+climbStairs(n-2);
        }
        else
            return 1;
    }
};

https://leetcode.com/problems/climbing-stairs/solutions/3708750/4-method-s-beat-s-100-c-java-python-beginner-friendly
*/

class Solution {
public:
    int climbStairs(int n, unordered_map<int, int>& memo) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (memo.find(n) == memo.end()) {
            memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
        }
        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }
};