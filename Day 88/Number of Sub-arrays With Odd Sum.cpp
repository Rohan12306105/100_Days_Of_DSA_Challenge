/*
https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/solutions/6464951/beats-100-number-of-sub-arrays-with-odd-7wf1w
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, prefixSum = 0;
        for(int a : arr) {
            prefixSum += a;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1'000'000'007;
    }
};