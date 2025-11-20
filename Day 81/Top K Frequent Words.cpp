/*
https://leetcode.com/problems/top-k-frequent-words/solutions/7003764/leetcode-692-top-k-frequent-words-c-solu-mdqq
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (string &s : words) {
            mpp[s]++;
        }

        priority_queue<pair<int, string>> pq;
        for (auto &it : mpp) {
            pq.push({-it.second, it.first});
            if (pq.size() > k) pq.pop();
        }

        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};