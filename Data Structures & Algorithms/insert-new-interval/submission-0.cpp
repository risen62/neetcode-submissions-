class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        int i = 0;
        while(i<n &&  intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        while (i < n) {
            if (newInterval[0] <= intervals[i][1] && newInterval[1] >= intervals[i][0]) {  // merge
                int min_bound = min(intervals[i][0], newInterval[0]);
                int max_bound = max(intervals[i][1], newInterval[1]);
                newInterval[0] = min_bound;
                newInterval[1] = max_bound;
            }else{
                break;
            }
            i++;
        }
         result.push_back(newInterval);

         while(i<n){
            result.push_back(intervals[i]);
            i++;
         }

          return result;
    }
};
