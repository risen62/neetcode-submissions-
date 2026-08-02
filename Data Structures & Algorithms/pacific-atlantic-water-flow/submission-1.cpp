class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific = bfs(heights, rows, cols, true);
        vector<vector<bool>> atlantic = bfs(heights, rows, cols, false);
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] == true  && atlantic[i][j] == true) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    vector<vector<bool>> bfs(vector<vector<int>>& heights, int rows, int cols, bool isPacific) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        // Initialize with appropriate edges
        if (isPacific == true) {
            //left column
            for (int i = 0; i < rows; i++) {
                q.push({i, 0});
                visited[i][0] = true;
            }
            // top row
            for (int j = 0; j < cols; j++) {
                q.push({0, j});
                visited[0][j] = true;
            }
        } else {
            //  right column
            for (int i = 0; i < rows; i++) {
                q.push({i, cols - 1});
                visited[i][cols - 1] = true;
            }
            //Bottom row 
            for (int j = 0; j < cols; j++) {
                q.push({rows - 1, j});
                visited[rows - 1][j] = true;
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && visited[nr][nc] == false && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return visited;
    }
};