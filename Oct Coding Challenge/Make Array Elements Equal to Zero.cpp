/*
https://leetcode.com/problems/make-array-elements-equal-to-zero/solutions/7306415/make-array-elements-equal-to-zero-breakout-game-o-n-beats-100
*/
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int len = nums.size(), count = 0, left = 0, right = 0;
        for (int v : nums) right += v;
        for (int i = 0; i < len; i++) {
            left += nums[i];
            right -= nums[i];
            if (nums[i] != 0) continue;
            if (left == right) count += 2;
            if (abs(left - right) == 1) count++;
        }
        return count;
    }
};
