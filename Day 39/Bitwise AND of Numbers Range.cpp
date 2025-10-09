/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/solutions/4759881/beats-100-users-c-java-python-javascript-explained
*/


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};
