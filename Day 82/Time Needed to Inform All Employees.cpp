/*
https://leetcode.com/problems/time-needed-to-inform-all-employees/solutions/3591420/video-explanation-including-visualizatio-84lt
*/
// Solved using BFS
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		int res = 0, len, curTime, curNode;
        pair<int, int> curNodeInfo;
        vector<vector<int>> paths(n);
        for (int id = 0; id < n; id++) if (id != headID) paths[manager[id]].push_back(id);
        queue<pair<int, int>> q;
        q.push({0, headID});
        while (q.size()) {
            len = q.size();
            for (int i = 0; i < len; i++) {
                curNodeInfo = q.front();
                curTime = curNodeInfo.first;
                curNode = curNodeInfo.second;
                if (paths[curNode].size()) {
                    for (auto node: paths[curNode]) q.push({curTime + informTime[curNode], node});
                }
                else res = max(curTime, res);
                q.pop();
            }
        }
        return res;
    }
};