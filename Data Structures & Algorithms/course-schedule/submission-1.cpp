class Solution {
   public:
    bool isCycleDFS(int src, vector<bool>& visited, vector<bool>& recpath, vector<vector<int>>& edges) {
        visited[src] = true;
        recpath[src] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src) {
                if (visited[v] == false) {
                    if (isCycleDFS(v, visited, recpath, edges)) {
                        return true;
                    }
                } else if (recpath[v] == true) {
                    return true;
                }
            }
        }
        recpath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<bool> recpath(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                if (isCycleDFS(i, visited, recpath, edges) == true) {
                    return false;
                }
            }
        }
        return true;
    }
};
