/*
if price is increasing element by element
profit is always equal to i - (i-1) ki value
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for (int i = 1; i < prices.size(); i++){
            if(prices[i]>prices[i-1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
        
    }
};