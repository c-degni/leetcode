class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        std::sort(points.begin(), points.end());
        int end = points[0][1];
        int earliestEnd = end;
        int r = 1;
        for (vector<int> &p : points) {
            if (p[0] > end || p[0] > earliestEnd) {
                r++;
                end = p[1];
                earliestEnd = end;
            } else {
                earliestEnd = std::min(earliestEnd, p[1]);
            }
        }
        return r;
    }
};
