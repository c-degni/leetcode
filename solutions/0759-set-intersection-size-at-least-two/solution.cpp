class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });

        int last1 = -1;
        int last2 = -1;
        int t = 0;

        for (auto &i : intervals) {
            if (last2 < i[0]) {
                t += 2;
                last2 = i[1];
                last1 = last2 - 1;
            } else if (last1 < i[0]) {
                t += 1;
                last1 = last2;
                last2 = i[1];
            }
        }
        return t;
    }
};
