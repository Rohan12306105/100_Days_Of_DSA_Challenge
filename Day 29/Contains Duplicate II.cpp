/*


this will give TLE , to prevent TLE use a hashmap

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[i]==nums[j]){
                    int x = i - j;
                    int y = abs(x);
                    if(y<=k){
                        return true;
                    }
                    continue;
                }
            }
            
        }
        return false;
    }
};


*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int  i = 0; i < n; i++)
        {
                        // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i])){
                if(abs(i-mp[nums[i]])<=k){ // if I have already seen this number, then check for condition abs(i - j) <= k
                    return true;
                }
            }
            mp[nums[i]] = i;
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            
        }
        return false;
    }
};