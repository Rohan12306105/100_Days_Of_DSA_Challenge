/*
https://leetcode.com/problems/smallest-number-with-all-set-bits/solutions/7309010/5-ways-of-1-line-codes-vs-binary-search-beats-100
*/

class Solution {
public:
    int smallestNumber(unsigned n) {
        return bit_ceil(n+1)-1;
    }
};