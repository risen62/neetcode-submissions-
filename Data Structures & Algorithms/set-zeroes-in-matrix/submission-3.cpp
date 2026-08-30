class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<pair<int, int>> zeropositions;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 0) {
                    zeropositions.push_back({i, j});
                }
            }
        }
        for (int k = 0; k < zeropositions.size(); k++) {
            int zerorow = zeropositions[k].first;
            int zerocolumn = zeropositions[k].second;
            for(int i = 0;i<columns;i++){
                matrix[zerorow][i] = 0;
            }
            for(int i = 0;i<rows;i++){
                matrix[i][zerocolumn] = 0;
            }
        }
    }
};
