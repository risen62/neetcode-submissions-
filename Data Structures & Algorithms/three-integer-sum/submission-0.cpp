class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqueTriplets;
        
        // Check every possible combination of 3 indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
        
        // Convert set to vector
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};