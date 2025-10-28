/*

*/
class Solution {
public:
    // dp[day_index][transactions_left][is_holding_stock]
    // is_holding_stock: 0 = No, 1 = Yes
    int dp[1005][105][2];

    /**
     * Helper function to find the maximum profit using recursion with memoization.
     *
     * @param prices The array of stock prices.
     * @param day The current day we are considering (index in prices).
     * @param k The number of complete (buy + sell) transactions remaining.
     * @param isHoldingStock 0 if we are not holding a stock (can buy),
     * 1 if we are holding a stock (must sell).
     * @return The maximum profit achievable from this day onwards given the state.
     */
    int findMaxProfit(vector<int>& prices, int day, int k, int isHoldingStock) {
        
        // Base Case: If we've run out of days, no more profit can be made.
        if (day >= prices.size()) {
            return 0;
        }

        // Memoization Check: If we've solved this subproblem, return the stored result.
        if (dp[day][k][isHoldingStock] != -1) {
            return dp[day][k][isHoldingStock];
        }

        // --- Define our choices ---

        // Choice 1: Do Nothing (Skip this day)
        // We move to the next day with the same k and holding status.
        int profit_from_skipping = findMaxProfit(prices, day + 1, k, isHoldingStock);

        int profit_from_acting = 0; // The profit from either buying or selling

        if (isHoldingStock == 1) {
            // We are holding a stock, so our only "action" is to SELL.
            // We gain prices[day], use up one transaction (k - 1), and are no longer holding (0).
            profit_from_acting = prices[day] + findMaxProfit(prices, day + 1, k - 1, 0);
        
        } else {
            // We are not holding a stock, so our only "action" is to BUY.
            // We can only buy if we still have transactions left (k > 0).
            if (k > 0) {
                // We "spend" prices[day] (hence -prices[day]).
                // We move to the next day, k is unchanged (only decrements on sell),
                // and we are now holding a stock (1).
                profit_from_acting = -prices[day] + findMaxProfit(prices, day + 1, k, 1);
            }
        }

        // The best we can do is the max of skipping or acting (buying/selling).
        int max_profit = max(profit_from_skipping, profit_from_acting);

        // Store the result in our DP table and return it.
        return dp[day][k][isHoldingStock] = max_profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        // Initialize the DP table with -1 to indicate "not yet computed".
        memset(dp, -1, sizeof(dp));
        
        // Start the recursion:
        // - prices: The price list
        // - 0: Start on day 0
        // - k: With k transactions allowed
        // - 0: Starting by not holding any stock
        return findMaxProfit(prices, 0, k, 0);
    }
};