class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);  // ✅ Added this
        int answer;
        int a = nums[0];
        int b = max(nums[0],nums[1]);
        
        
        for (int i = 2; i < n; i++) {
            answer = max(a + nums[i],b);
            a = b;
            b = answer; 
        }
        
        return answer;
    }
};