class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1l = str1.length();
        int s2l = str2.length();

        for (int i = min(s1l, s2l); i > 0; i--) {
            string cur = str1.substr(0, i);
            string cur1 = "";
            string cur2 = "";
            if (s1l % i == 0 && s2l % i == 0) {
                for (int j = 0; j < s1l / i; j++) cur1 += cur;
                for (int j = 0; j < s2l / i; j++) cur2 += cur;
                if (cur1 == str1 && cur2 == str2) return cur;
            }
        }
        return "";
    }
};
