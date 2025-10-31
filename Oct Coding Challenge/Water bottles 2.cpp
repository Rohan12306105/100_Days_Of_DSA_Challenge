/*
https://leetcode.com/problems/water-bottles-ii/solutions/7241229/intuitive-explanation-c-python-java
*/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int x) {
        int ans = numBottles;
        while (numBottles >= x) {
            numBottles -= x - 1, x++, ans++;
        }
        return ans;
    }
};