class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int, int> map;

        for (int &i : arr) {
            if (map.contains(i)) {
                map[i]++;
            } else {
                map.insert({i, 1});
            }
        }

        std::unordered_set<int> set;
        for (auto &pair : map) {
            if (set.contains(pair.second)) {
                return false;
            }
            set.insert(pair.second);
        }

        return true;
    }
};
