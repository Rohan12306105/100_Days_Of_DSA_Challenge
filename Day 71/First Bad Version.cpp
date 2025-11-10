/*
https://leetcode.com/problems/first-bad-version/solutions/6613323/easy-solution-handwritten-notes-2-approa-ufxs
*/

class Solution  {
public:
    int firstBadVersion(int n) {
        int l = 0, h = n;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isBadVersion(mid)) h = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};