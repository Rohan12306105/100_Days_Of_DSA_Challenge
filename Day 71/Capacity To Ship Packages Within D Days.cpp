/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/solutions/7277678/binary-search-c-python-java-easy-approac-xcxp
*/

class Solution {
public:
    int FindDays(vector<int>& weights, int capacity) {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + load > capacity) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (FindDays(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};