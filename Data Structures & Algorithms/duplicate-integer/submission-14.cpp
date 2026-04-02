class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int low = 0;
        int high = 0;
        int size = nums.size();
        for(int i = 0;i<size;i++){
            if(nums[i] < low){
                low = nums[i];
            }
            else if(nums[i] > high){
                high = nums[i];
            }
        }
        vector <int> H(high - low + 1);
        for(int i = 0;i<size;i++){
            H[nums[i] - low]++;
        }
        for(int i  = 0;i<H.size();i++){
             if(H[i] > 1){
            return true;
        }
     }
     return false;
    }
};