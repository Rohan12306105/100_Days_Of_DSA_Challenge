/*
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/solutions/7278459/easy-on-code-explanation-with-comments-b-9xp7
*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        
        // Step 1: Compute prefix sum for fast range-sum lookup
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Step 2: maxFirstLen[i] = max sum of any subarray of length firstLen ending at or before i
        //          maxSecondLen[i] = max sum of any subarray of length secondLen ending at or before i
        vector<int> maxFirstLen(n, 0), maxSecondLen(n, 0);
        maxFirstLen[firstLen - 1] = prefixSum[firstLen - 1];
        maxSecondLen[secondLen - 1] = prefixSum[secondLen - 1];

        for (int i = firstLen; i < n; i++) {
            int currSum = prefixSum[i] - prefixSum[i - firstLen]; // ending at i
            maxFirstLen[i] = max(maxFirstLen[i - 1], currSum); // best sum ending at or before i
        }
        for (int i = secondLen; i < n; i++) {
            int currSum = prefixSum[i] - prefixSum[i - secondLen]; // edning at i
            maxSecondLen[i] = max(maxSecondLen[i - 1], currSum); // best sum ending at or before i
        }

        // Step 3: Try both orders of subarrays
        int maxSum = 0;
        for (int i = firstLen + secondLen - 1; i < n; i++) {
            // Case 1: firstLen subarray comes before secondLen
            int secondSum = prefixSum[i] - prefixSum[i - secondLen]; // ending at index i
            maxSum = max(maxSum, secondSum + maxFirstLen[i - secondLen]); // best firstLen sum till i - secondLen 

            // Case 2: secondLen subarray comes before firstLen
            int firstSum = prefixSum[i] - prefixSum[i - firstLen]; // ending at index i
            maxSum = max(maxSum, firstSum + maxSecondLen[i - firstLen]); // best secondLen sum till i - firstLen 
        }

        return maxSum;
    }
};