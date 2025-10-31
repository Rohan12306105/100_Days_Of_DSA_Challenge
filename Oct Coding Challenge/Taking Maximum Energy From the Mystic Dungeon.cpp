/*
https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/solutions/7262920/taking-maximum-energy-from-mystic-dungeon-beat-100-java-c-c-c-python3-go-js-ts
*/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int result = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = energy[i] + ((i + k < n) ? dp[i + k] : 0);
            result = max(result, dp[i]);
        }
        return result;
    }
};