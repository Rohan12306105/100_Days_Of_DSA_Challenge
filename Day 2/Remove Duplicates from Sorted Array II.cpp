/*
2 pointers lene h i=2 & j=2
agar nums[j]!=nums[i-2] meet krti h toh then i ki position par j ko push kardo 
and then i++
if not, then only j++
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=2;
        for (int j = 2; j < nums.size(); j++)
        {
            if (nums[j]!=nums[i-2])
            {
                nums[i] = nums[j];
                i++;
            }
            
        }
        return i;
    }
};

//alternate solution - solves all possible test cases
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;

        if (nums.size() <= 2) return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;       
    }
};
