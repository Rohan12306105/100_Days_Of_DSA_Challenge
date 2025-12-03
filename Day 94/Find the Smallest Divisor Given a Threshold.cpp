/*
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/solutions/7269639/binary-search-easy-solution-optimised-ap-prya
*/

class Solution {
public:
    int MaxElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1];
    }

    int divisor(vector<int>& nums, int mid) {
        int sum = 0;
        for (int val : nums) {
            sum += ceil((double)val / (double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = MaxElement(nums);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (divisor(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};