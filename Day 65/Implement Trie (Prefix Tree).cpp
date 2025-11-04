/*
https://leetcode.com/problems/implement-trie-prefix-tree/solutions/6985000/cpp-trie-100-beats-easy-to-understand-by-0u1x
*/

class TrieNode {
    public:
        vector<TrieNode *>v;
        bool isEnd;
        TrieNode() : v(26, nullptr) , isEnd(false){}
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->v[word[i] - 'a'] == nullptr) {
                node->v[word[i] - 'a'] = new TrieNode();
            }
            node = node->v[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->v[word[i] - 'a'] == nullptr) return false;
            node = node->v[word[i] - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            if (node->v[prefix[i] - 'a'] == nullptr) return false;
            node = node->v[prefix[i] - 'a'];
        }
        return true;
    }
};