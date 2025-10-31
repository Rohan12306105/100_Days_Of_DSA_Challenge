/*
https://leetcode.com/problems/calculate-money-in-leetcode-bank/solutions/7298386/very-simple-intuitive-o-1-solution-beats-100
*/
class Solution {
public:
    int triSum(int n) { 
        return (n * (n + 1)) >> 1;
    }

    int totalMoney(int days) {
        int nWeeks = days / 7;
        int rDays = days % 7;       

        return triSum(days) - 42 * triSum(nWeeks - 1) - 6 * nWeeks * rDays;
    }
};
