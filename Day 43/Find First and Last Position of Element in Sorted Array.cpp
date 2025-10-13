/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solutions/7268911/c-first-and-last-position-of-element-in-sorted-array-binary-search-o-log-n-time-o-1-spa
*/

class Solution {
public:
    int lower_indx(vector<int> nums,int size,int target){
        int left = 0;
        int right = size - 1;
        int first = -1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                first = mid;
                right = mid - 1;
            }
            else if(nums[mid]>target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return first;
    }
    int upper_index(vector<int> nums, int size, int target){

        int left = 0;
        int right = size-1;
        int last_index = -1;
        while(left <= right){

            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                last_index = mid;
                left = mid+1;
            } 
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return last_index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int lb = lower_indx(nums, size, target);
        if(lb==-1)
            return {-1, -1};
        int ub = upper_index(nums, size, target);
        return {lb, ub};
    }
};