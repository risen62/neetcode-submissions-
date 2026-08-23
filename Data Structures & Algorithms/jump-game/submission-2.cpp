class Solution {
   public:
    bool canjumpfrom(vector<int>& nums, int pos, vector<int>& memo) {
        if (memo[pos] != -1) {
            return memo[pos] == 1;
        } else {
            if (pos == nums.size() - 1) return true;
            if (nums[pos] == 0) return false;
            if (nums[pos] > 0) {
                for (int i = 1; i <= nums[pos]; i++) {
                    if (canjumpfrom(nums, pos + i,memo) == true) {
                        memo[pos] = 1;
                        return true;
                    }
                }
            }
            memo[pos] = 0;
            return false;
        }
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return canjumpfrom(nums, 0, memo);
    }
};
