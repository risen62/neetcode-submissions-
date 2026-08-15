class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_dp(n);
        vector<int> max_dp(n);
        int result = nums[0];
        min_dp[0] = nums[0];
        max_dp[0] = nums[0];
        for(int i = 1;i<n;i++){
            int candiate1 = nums[i];
            int candiate2 = nums[i] * min_dp[i-1];
            int candiate3 = nums[i] * max_dp[i-1];

            max_dp[i] = max({candiate1,candiate2,candiate3});
            min_dp[i] = min({candiate1,candiate2,candiate3});
            result = max(max_dp[i],result);
        }
        return result;

        
    }
};
