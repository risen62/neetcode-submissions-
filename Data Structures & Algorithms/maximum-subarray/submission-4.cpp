class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int maxsum = nums[0];
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(prev < 0){
                prev = nums[i];
            }else{
                prev = nums[i] + prev;
            }
            maxsum = max(prev,maxsum);
        }
        return maxsum;
    }
};
