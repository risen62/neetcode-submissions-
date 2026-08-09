class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>loot(n);
        if(n == 0)return 0;
        if(n == 1)return nums[0];
        loot[0] = nums[0];
        loot[1] = max(nums[0],nums[1]);
        for(int i = 2;i<nums.size();i++){
            loot[i] = max(loot[i-2] + nums[i],loot[i-1]);
        }
        return loot[n - 1];
    }
};