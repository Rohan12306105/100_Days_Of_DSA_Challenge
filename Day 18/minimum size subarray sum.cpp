#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = std::numeric_limits<int>::max();

        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                // Update minimum length and shrink the window
                ans = std::min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return (ans == std::numeric_limits<int>::max()) ? 0 : ans;
    }
};