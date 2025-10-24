/*
https://leetcode.com/problems/triangle/solutions/7221386/bottom-up-dynamic-programming-in-place-beats-100
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] +=
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]);

        return triangle[0][0];
    }
};