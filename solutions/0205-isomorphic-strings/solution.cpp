class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        if (n == 1) return true;
        std::unordered_map<char, char> m;
        std::unordered_set<char> seens;
        std::unordered_set<char> seent;
        for (int i = 0; i < n; i++) {
            if (seens.contains(s[i])) {
                if (m[s[i]] != t[i]) return false;
            } else if (seent.contains(t[i])) {
                return false;
            } else {
                m[s[i]] = t[i];
                seens.insert(s[i]);
                seent.insert(t[i]);
            }
        }
        return true;
    }
};
