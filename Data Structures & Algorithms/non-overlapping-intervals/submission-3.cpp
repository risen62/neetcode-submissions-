class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int result = 0;
        vector<int> current = intervals[0];
        for (int i = 1; i < n; i++) {
            vector<int> next = intervals[i];
            if (next[0] < current[1]) {
                result++;
                if (next[1] < current[1]) {
                    current = next;
                }
            } else {
                current = next;
            }
        }
        return result;
    }
};
