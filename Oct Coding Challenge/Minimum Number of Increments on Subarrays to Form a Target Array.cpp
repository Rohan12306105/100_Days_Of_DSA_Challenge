/*
https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/solutions/7312093/adjacent_differenceaccumulate-vs-1-passb-hpsr
*/

class Solution {
public:
    static int minNumberOperations(vector<int>& target) {
        adjacent_difference(target.begin(), target.end(), target.begin());
        return accumulate(target.begin(), target.end(), 0,
        [](int sum, int x){ return sum+=max(0,x);});
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();