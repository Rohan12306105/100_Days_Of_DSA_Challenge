/*
2 pointers lene hai i & k - zero se shuru krna

i ko k se compare krna h 
agar != aata h toh k=i krna h 
fir iterate krna h

*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};