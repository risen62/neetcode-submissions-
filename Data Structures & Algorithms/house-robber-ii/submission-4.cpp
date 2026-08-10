class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n  == 0)return 0;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);
        vector<int> loot1(n - 1);
        vector<int> loot2(n - 1);
        loot1[0] = nums[0];
        loot1[1] = max(nums[0],nums[1]); 
        for(int i = 2;i<n-1;i++){
            loot1[i] = max(nums[i] + loot1[i-2],loot1[i-1]);
        }
        loot2[0] = nums[1];
        loot2[1] = max(nums[1],nums[2]);
        for(int i  = 2;i<n - 1;i++){
            loot2[i] = max(nums[i+1] + loot2[i-2],loot2[i-1]);
        }

        int answer = max(loot1[n-2],loot2[n-2]);
        return answer;
        
    }
};
