/*
doesnt paases all the test cases cuz of TLE


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    vector<int> temp;
                    if(nums[i]+nums[j]+nums[k]==0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        s.insert(temp);
                    }
                }
            }
        }
        for(auto allTriplets : s)
            output.push_back(allTriplets);
        return output;
        
    }
};*/

/*
//Bruteforce Approach - O(n^3) time and O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    vector<int> temp;
                    if(nums[i] + nums[j] + nums[k] == 0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        s.insert(temp);
                    }
                }
            }
        }
        for(auto allTriplets : s)
            output.push_back(allTriplets);
        return output;
    }
};
*/