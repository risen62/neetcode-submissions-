class Solution {
   public:
    bool dfs(int course, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& instack) {
        visited[course] = true;
        instack[course] = true;
        for (auto depends_on : graph[course]) {
            if (instack[depends_on] == true) {
                return true;
            }
            if (visited[depends_on] == false) {
                if (dfs(depends_on, graph, visited, instack) == true) {
                    return true;
                }
            }
        }
        instack[course] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> instack(numCourses, false);
        for (auto pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            graph[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                if (dfs(i, graph, visited, instack) == true) {
                    return false;
                }
            }
        }
        return true;
    }
};
