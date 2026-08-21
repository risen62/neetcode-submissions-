class Solution {
   public:
    int LCSlogic(int i, int j, string text1, string text2, vector<vector<int>>& memo) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (memo[i][j] != -1) return memo[i][j];
        if (text1[i] == text2[j]) {
            memo[i][j] = LCSlogic(i - 1, j - 1, text1, text2, memo) + 1;
        } else {
            memo[i][j] =
                max(LCSlogic(i - 1, j, text1, text2, memo), LCSlogic(i, j - 1, text1, text2, memo));
        }
        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.length() - 1;
        int j = text2.length() - 1;
        vector<vector<int>> memo(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        return LCSlogic(i, j, text1, text2, memo);
    }
};