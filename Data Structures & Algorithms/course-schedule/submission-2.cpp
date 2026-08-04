class Solution {
public:
    bool isCycleDFS(int src, vector<bool>& visited, vector<bool>& recpath, vector<vector<int>>& adj) {
        visited[src] = true;
        recpath[src] = true;

        for (int v : adj[src]) {  // Only check neighbors, not all edges!
            if (visited[v] == false) {
                if (isCycleDFS(v, visited, recpath, adj)) {
                    return true;
                }
            } else if (recpath[v] == true) {
                return true;
            }
        }
        
        recpath[src] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        // Build adjacency list: b → a
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);  // b → a
        }
        
        vector<bool> visited(n, false);
        vector<bool> recpath(n, false);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                if (isCycleDFS(i, visited, recpath, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};