class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
         int i = 0;
        int n = intervals.size();
        vector<vector<int>> result;
        while (i < n) {
            vector<int> current = intervals[i];
            i++;
            while (i < n) {
                vector<int> next = intervals[i];
                if (next[0] <= current[1]) {
                    current[1] = max(next[1], current[1]);
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
