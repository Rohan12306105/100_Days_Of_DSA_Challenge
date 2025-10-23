/*
https://leetcode.com/problems/longest-increasing-subsequence/solutions/6092590/video-keep-elements-in-ascending-order
*/



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for (int n : nums) {
            if (res.empty() || res.back() < n) {
                res.push_back(n);
            } else {
                int idx = binarySearch(res, n);
                res[idx] = n;
            }
        }

        return res.size();        
    }

private:
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }    
};