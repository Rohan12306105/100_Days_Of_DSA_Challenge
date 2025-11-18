/*

https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/solutions/3570268/all-possible-solution-with-explanation-d-0pey
*/

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        vector<int> rowPaths(rows);
        vector<int> colPaths(cols);
        unordered_map<int, vector<vector<int>>> valuePositions;
        vector<vector<int>> temp(rows, vector<int>(cols));
        set<int> uniqueValues;

        // Populate valuePositions and uniqueValues
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int value = matrix[i][j];
                valuePositions[-value].push_back({i, j});
                uniqueValues.insert(-value);
            }
        }

        // Calculate longest paths
        for (int value : uniqueValues) {
            for (const auto& position : valuePositions[value]) {
                int row = position[0];
                int col = position[1];
                temp[row][col] = max(rowPaths[row], colPaths[col]) + 1;
            }

            for (const auto& position : valuePositions[value]) {
                int row = position[0];
                int col = position[1];
                rowPaths[row] = max(rowPaths[row], temp[row][col]);
                colPaths[col] = max(colPaths[col], temp[row][col]);
            }
        }

        // Return the maximum path length
        return max(*max_element(rowPaths.begin(), rowPaths.end()), *max_element(colPaths.begin(), colPaths.end()));
    }
};