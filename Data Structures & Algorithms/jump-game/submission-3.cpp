class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int finalposition = n - 1;
        for(int i = n  - 2;i>=0;i--){
            if(i  + nums[i] >= finalposition){
                finalposition = i;
            }
        }
        return finalposition == 0;       
    }
};
