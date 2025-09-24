/*
https://leetcode.com/problems/word-pattern/solutions/7192429/word-pattern-simple-easy-beats-100-in-tc-beats-70-in-sc
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int m = pattern.size();
        vector<string> words;
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            words.push_back(temp);
        }
        int n = words.size();
        if(m != n) return false;

        unordered_map<char, string> mp;
        unordered_set<string> s2;
        for(int i = 0; i < m; i++){
            if((mp.find(pattern[i]) == mp.end()) && (s2.find(words[i]) == s2.end())){
                mp[pattern[i]] = words[i];
                s2.insert(words[i]);
            }else if(mp[pattern[i]] != words[i]){
                return false;
            }
        }
        return true;
    }
};