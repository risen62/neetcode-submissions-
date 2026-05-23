class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        
        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;
            
            if(umap.find(second) != umap.end()) {
                return {umap[second], i};  
            }
            umap[first] = i;
        }  
        return {};
    }
};