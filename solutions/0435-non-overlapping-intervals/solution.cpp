class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int s = intervals.size();
        std::sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int r = 0;
        for (int i = 1; i < s; i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            } else {
                r++;
                end = std::min(intervals[i][1], end);
            }
        }
        return r;
    }
};
