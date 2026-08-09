class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);  // ✅ Added this
        
        int A = nums[0];
        int B = max(nums[0], nums[1]);
        int answer;
        
        for (int i = 2; i < n; i++) {
            answer = max(A + nums[i], B);
            A = B;
            B = answer;
        }
        
        return answer;
    }
};