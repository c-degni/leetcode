class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.length();
        if (slen == 1) return 1;

        int i = 0;
        int m = 0;
        while (i < slen) {
            std::unordered_map<char, int> map; // char : idx
            while(map.find(s[i]) == map.end() && i < slen) {
                map[s[i]] = i;
                m = std::max((int)map.size(), m);
                i++;
            }
            if (i < slen) i = map.find(s[i])->second + 1;
        }
        return m;
    }
};
