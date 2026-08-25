class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;
        while(i<n){
            vector<int>current  = intervals[i];
            i++;
            while(i<n){
                vector<int> next = intervals[i];
                if(next[0]<= current[1]){
                    current[1] = max(current[1],next[1]);
                    i++;
                }else{
                    break;
                }
            }
            result.push_back(current);
        }
        return result;   
    }
};
