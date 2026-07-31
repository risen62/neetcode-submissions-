class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                if (grid[r][c] == '1'  ) {
                    count ++;
                    dfs(grid,r,c,rows,columns);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>> & grid, int r, int c,int rows,int columns) {
            if (r < 0 || r >= rows || c < 0 || c >= columns) return;
            if (grid[r][c] == '0') return;
            grid[r][c] = '0';
            dfs(grid, r + 1, c,rows,columns);
            dfs(grid, r - 1, c,rows,columns);
            dfs(grid, r , c + 1,rows,columns);
            dfs(grid, r , c - 1,rows,columns);
        }
};
