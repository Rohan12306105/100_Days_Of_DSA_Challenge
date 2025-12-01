/*
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/solutions/3444403/cjavapythonjavascript-fully-explained-ma-k1vw
*/
class Solution {
public:
     bool isPossibleDivide(vector<int>& nums, int k) {
         map<int,int> map;
         for(int num : nums){
             map[num]++;
         }
         while(map.size()!=0){
             int first = map.begin()->first;
             for(int i=first; i<first+k; i++){
                 if(!map.count(i)){
                     return false;
                 }
                 map[i]--;
                 if(map[i]==0){
                     map.erase(i);
                 }
             }
         }
         return true;
     }
 };


 // approach 2

 class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }
        
        unordered_map<int,int> map;
        for (int num : nums) {
            map[num]++;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int num : nums) {
            if (map[num] > 0) {
                for (int i = num + 1; i < num + k; i++) {
                    if (map[i] == 0) {
                        return false;
                    }
                    map[i]--;
                }
                map[num]--;
            }
        }
        
        return true;
    }
};