
//https://leetcode.com/problems/longest-consecutive-sequence/solutions/3171985/best-c-4-solution-hash-table-sorting-brute-force-optimize-one-stop-solution/#:~:text=Approach.%0A%0A*/%0A%0A%0A/*****************************************-,Approach%202%20Code,-*****************************************/%0A%0Aclass%20Solution
/*
dont try the brute force approach , as it takes On^3 time

the bellow is the fastest approach with O logn time , its a sorted + modified version of bruteforce 
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int curr = 1;
        int longsub = 0;
        for (int i = 1; i < n; i++)
        {
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    curr++;
                }
                else{
                    longsub = max(longsub, curr);
                    curr = 1;
                }
            }
        }
        return max(longsub, curr);
    }
};