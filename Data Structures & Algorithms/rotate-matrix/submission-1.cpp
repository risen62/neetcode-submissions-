class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i = 0;i<rows;i++){
            for(int j = i+1;j<columns;j++){
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        for(int i = 0;i<rows;i++){
            int left = 0;
            int right = columns  - 1;
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};
