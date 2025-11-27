/*
https://leetcode.com/problems/global-and-local-inversions/solutions/7138418/global-and-local-inversion-optimal-solut-rtge
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};
