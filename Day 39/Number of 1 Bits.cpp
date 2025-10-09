/*
https://leetcode.com/problems/number-of-1-bits/solutions/6942378/beats-100-00-2-approach-brute-force-optimal
*/
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};