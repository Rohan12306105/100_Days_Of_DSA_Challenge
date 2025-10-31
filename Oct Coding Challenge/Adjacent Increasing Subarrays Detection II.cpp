/*
https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/solutions/7275958/1-pass-103ms-beats-98-12
*/

class Solution {
public:
    static int maxIncreasingSubarrays(vector<int>& nums) {
        const int n=nums.size();
        int len=1, prev=0, k=0;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) len++; 
            else{
                k=max({k, len/2, min(len, prev)}); 
                prev=len;
                len=1;
            }
        }
        return max({k, len/2, min(len, prev)});
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();