class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> umap;
        vector <pair<int,int>> frequency;
        vector <int> ans;
        for(auto x : nums){
            umap[x]++;
        }
        for(auto y : umap){
            frequency.push_back({y.second,y.first});
        }  
        sort(frequency.rbegin(),frequency.rend());
        for(int i = 0;i<k;i++){
            ans.push_back(frequency[i].second);
        }
        return ans;
    }
};