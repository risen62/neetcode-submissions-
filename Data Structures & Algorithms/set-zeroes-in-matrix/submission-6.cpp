class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        bool firstRow = false;
        bool firstCol = false;
        
        // CHECK first row BEFORE modification
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }
        
        // CHECK first column BEFORE modification
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        
        // Mark zeros using first row and column as markers
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set inner matrix
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Handle first row
        if (firstRow) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Handle first column
        if (firstCol) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};