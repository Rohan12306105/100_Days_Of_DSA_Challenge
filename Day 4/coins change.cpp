/*
https://youtu.be/KnWorqyDSLA?si=Poq4Of4mKeAn3q2x
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int coin:coins){
            for (int curr_amount= coin; 
                    curr_amount <=amount; curr_amount++)
            {
                if(dp[curr_amount-coin]!=INT_MAX){
                    dp[curr_amount] = min(dp[curr_amount], dp[curr_amount - coin] + 1);
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};