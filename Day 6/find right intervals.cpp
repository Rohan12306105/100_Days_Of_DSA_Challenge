class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts(n);
        for (int i = 0; i < n; ++i) starts[i] = {intervals[i][0], i};
        sort(starts.begin(), starts.end());
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int target = intervals[i][1];
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (starts[mid].first >= target) high = mid - 1;
                else low = mid + 1;
            }
            if (low < n) res[i] = starts[low].second;
        }
        return res;
    }
};