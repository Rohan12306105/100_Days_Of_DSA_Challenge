/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/7261920/binary-search-easy-solution-100-beats-0ms-solution-for-beginners
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};