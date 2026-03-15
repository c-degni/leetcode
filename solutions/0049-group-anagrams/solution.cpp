class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, vector<string>> map;
        for (string &s : strs) {
            std::map<char, int> tmp;
            for (char &c : s) {
                if (tmp.find(c) == tmp.end()) {
                    tmp[c] = 1;
                } else {
                    tmp[c]++;
                }
            }
            if (map.find(tmp) == map.end()) {
                map[tmp] = {s};
            } else {
                map[tmp].push_back(s);
            }
        }

        vector<vector<string>> out;
        for (auto &[m, arr] : map) {
            out.push_back(arr);
        }
        return out;
    }
};
