/*
https://leetcode.com/problems/island-perimeter/solutions/5038982/full-explanation-with-dry-run-easy-solut-at0e
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // you have to traverse each block and check if its neighbour is 1 or 0.
        // suppose at grid[i][j] = 1, we will have to check all 4 of its
        // neighbours , if a neighbour has 0, we increment the perimeter
        // counter, if neighbour has 1, we dont do anything.

        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if ((j > 0 && grid[i][j - 1] == 0) || j == 0)
                        cnt++;

                    if ((i > 0 && grid[i - 1][j] == 0) || i == 0)
                        cnt++;

                    if ((j < m - 1 && grid[i][j + 1] == 0) || j == m - 1)
                        cnt++;

                    if ((i < n - 1 && grid[i + 1][j] == 0) || i == n - 1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
