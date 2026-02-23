class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int slen = s.length();
        if (k == 1 && slen < 2) return false;

        int p = std::pow(2, k);
        std::unordered_set<std::string> set;
        for (int i = 0; i + k - 1 < slen; i++) {
            std::string tmp = "";
            for (int j = i; j < i + k; j++) {
                tmp += s[j];
            }
            set.insert(tmp);
            if (set.size() == p) return true;
        }
        return false;
    }
};
