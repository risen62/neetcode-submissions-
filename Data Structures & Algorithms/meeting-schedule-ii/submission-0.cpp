class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        
        // ✅ CRITICAL: Sort intervals by start time
        sort(intervals.begin(), intervals.end(), 
             [](const Interval &a, const Interval &b) { 
                 return a.start < b.start; 
             });
        
        vector<int> start;
        vector<int> end;
        int n = intervals.size();
        
        for(int i = 0; i < n; i++) {
            start.push_back(intervals[i].start);
        }
        for(int i = 0; i < n; i++) {
            end.push_back(intervals[i].end);
        }
        
        // ✅ Sort end times separately (starts are already sorted)
        // sort(start.begin(), start.end()); // Not needed - already sorted!
        sort(end.begin(), end.end());
        
        int i = 0;
        int j = 0;
        int answer = 0;
        int count = 0;
        
        while(i < start.size() && j < end.size()) {
            if(start[i] < end[j]) {
                i++;
                count++;
                answer = max(count, answer);
            } else {
                j++;
                count--;
            }
        }
        return answer;
    }
};