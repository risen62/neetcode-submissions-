/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty())return true;
       sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b)
       {
        return a.start < b.start;
       }
    );
        Interval current = intervals[0];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            Interval next = intervals[i];
            if (next.start < current.end) {
                return false;
            } else {
                current = next;
            }
        }
        return true;
    }
};
