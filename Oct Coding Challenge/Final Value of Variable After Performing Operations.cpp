class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto& op : operations){
            int ans = 44 - op[1];
            x += ans;
        }
        return x;
    }
};