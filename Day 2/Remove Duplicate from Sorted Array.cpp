/*
2 pointers lene h i=1 & j=1
agar nums[j]!=nums[i-1] meet krti h toh then i ki position par j ko push kardo 
and then i++
if not, then only j++
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j]!=nums[i-1])
            {
                nums[i] = nums[j];
                i++;
            }
            
        }
        return i;
    }
};