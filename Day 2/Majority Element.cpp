/*
majority element = jo size / 2 se zyada occur hota 

isiliye pehle sort kra , and size / 2 element of run kra dia
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(nums.size()) / 2];
    }
};