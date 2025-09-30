/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/7178660/n-log-n-super-easy-explanation-java-c-python-javascript
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // Sort by end coordinate
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the previous arrow's end point,
            // we need a new arrow.
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};