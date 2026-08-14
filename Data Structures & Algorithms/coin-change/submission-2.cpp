class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    int remainder = i - coins[j];
                    if (dp[remainder] != INT_MAX) {
                        dp[i] = min(dp[i], 1 + dp[remainder]);
                    }
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};