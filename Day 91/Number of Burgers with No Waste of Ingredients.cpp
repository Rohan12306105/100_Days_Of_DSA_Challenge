/*
https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/solutions/7236083/c-single-line-only-clear-and-efficient-s-mpsx
*/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices & 1 || tomatoSlices > 4 * cheeseSlices || tomatoSlices < 2 * cheeseSlices) return {};
        return {tomatoSlices / 2 - cheeseSlices , 2 * cheeseSlices - tomatoSlices / 2};
    }
};