class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        for (const auto& interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0, rooms = 0, maxRooms = 0;
        
        while (i < start.size() && j < end.size()) {
            if (start[i] < end[j]) {
                i++;
                rooms++;
                maxRooms = max(maxRooms, rooms);
            } else {
                j++;
                rooms--;
            }
        }
        
        return maxRooms;
    }
};