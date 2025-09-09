/*
h-index formula is n-i ( only for sorted arrays )
where : n = size & i is the current index
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; i++) {
            int x = n - i;
            if (citations[i] >= x) {
                return x;
            }
        }
        return 0;
    }
};