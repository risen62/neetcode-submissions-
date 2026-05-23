class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexed_nums; // store (value, original_index)

        for (int i = 0; i < n; i++) {
            indexed_nums.push_back({nums[i], i});
        }

        sort(indexed_nums.begin(), indexed_nums.end());
        
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            int sum = indexed_nums[i].first + indexed_nums[j].first;
            if (sum == target) {
                // Get the original indices
                int idx1 = indexed_nums[i].second;
                int idx2 = indexed_nums[j].second;
                
                // Return in ascending order
                if (idx1 < idx2) {
                    return {idx1, idx2};
                } else {
                    return {idx2, idx1};
                }
            } 
            else if (sum < target) {
                i++;
            } 
            else {
                j--;
            }
        }
        
        return {}; // Should never reach here for valid input
    }
};