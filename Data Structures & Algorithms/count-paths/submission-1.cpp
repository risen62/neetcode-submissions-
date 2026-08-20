class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        matrix[0][0] = 1;

        for(int i = 1;i<n;i++){
            matrix[0][i] = 1;
        }
        for(int i = 1 ;i<m;i++){
            matrix[i][0] = 1;
        }

        for(int k =  1;k <m;k++)   { // to change columns
            for(int j = 1;j<n;j++ ){   //to fill rows
            matrix[k][j] = matrix[k - 1][j] + matrix[k][j-1];
            }
        }  

        return matrix[m-1][n-1];
    }
};
