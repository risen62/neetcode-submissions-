class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;
        int count = 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int total = rows * columns;
        vector<int> result;
        
        result.push_back(matrix[i][j]);
        matrix[i][j] = INT_MIN;  // Mark as visited
        count++;
        
        while(count < total) {
            while(j + 1 < columns && matrix[i][j+1] != INT_MIN) { //right
                j++;
                result.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;  // Mark as visited
                count++;
            }
            while(i + 1 < rows && matrix[i+1][j] != INT_MIN) { //down
                i++;
                result.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;  // Mark as visited
                count++;
            }
            while(j - 1 >= 0 && matrix[i][j-1] != INT_MIN) { //left
                j--;
                result.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;  // Mark as visited
                count++;
            }
            while(i - 1 >= 0 && matrix[i-1][j] != INT_MIN) { //up
                i--;
                result.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;  // Mark as visited
                count++;
            }
        }
        return result;
    }
};