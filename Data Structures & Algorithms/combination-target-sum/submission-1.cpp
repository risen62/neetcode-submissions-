class Solution {
   private:
    void backtrack(int start, int remaining, vector<int> &combo,vector<vector<int>> &result,vector<int>& nums) {
        if(remaining == 0){
            result.push_back(combo);
            return;
        }
        for(int i = start;i<nums.size();i++){
            if(nums[i] > remaining){
                break;
            }
            combo.push_back(nums[i]);
            backtrack(i,remaining-nums[i],combo,result,nums);
            combo.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int>combo;
       vector<vector<int>> result;
       sort(nums.begin(),nums.end());
       backtrack(0,target,combo,result,nums);
       return result;
    }
};
