/*
https://leetcode.com/problems/number-of-provinces/solutions/7269040/very-easy-explanation-dfs-approach-java-zpwsm
*/

class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected) {
        visited[node] = true;
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            if (isConnected[node][i] == 1 && !visited[i])
                dfs(i, visited, isConnected);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};