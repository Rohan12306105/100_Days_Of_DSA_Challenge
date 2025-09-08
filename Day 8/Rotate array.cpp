/*
We need to rotate the array k times to the right.
A clever trick is to notice that rotating is just about 
reversing parts of the array:

1.Reverse the entire array.
2.Reverse the first k elements.
3.Reverse the remaining n - k elements.
This works because reversing twice restores 
order — but now with elements shifted to the right.


Dry Run Example
Example: nums = [1,2,3,4,5,6,7], k = 3

1️. Reverse all:
[7,6,5,4,3,2,1]

2️. Reverse first k=3:
[5,6,7,4,3,2,1]

3️. Reverse last n-k=4:
[5,6,7,1,2,3,4] 
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; //if k>=n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};