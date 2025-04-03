class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int s = intervals.size();
        if (s == 1) return intervals;

        map<pair<int, int>, int> m;
        map<int, int> dup;

        for (int i = 0; i < s; i++) {
            if (dup.find(intervals[i][0]) != dup.end()) {
                dup[intervals[i][0]]++;
            } else {
                dup[intervals[i][0]] = 1;
            }
            m.insert({{intervals[i][0], dup[intervals[i][0]]}, intervals[i][1]});
        }

        map<pair<int, int>, int>::iterator it = m.begin();

        while (it != m.end()) {
            auto n = next(it);
            if (n != m.end()) {
                if (it->second >= n->first.first) {
                    it->second = max(it->second, n->second);
                    m.erase(n);
                    continue;
                } 
            }
            it++;
        }

        vector<vector<int>> ret;
        for (auto &pair: m) ret.push_back({pair.first.first, pair.second});
        return ret;
    }
};
