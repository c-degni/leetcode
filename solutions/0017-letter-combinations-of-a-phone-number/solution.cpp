class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;
        map<char, vector<char>> map = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        combinations("", 0, digits, map, out);
        return out;
    }

private:
    void combinations(string tmp, int i, string digits, map<char, vector<char>> &map, vector<string>& out) {
        if (tmp.length() == digits.length()) {
            out.push_back(tmp);
            return;
        }

        for (char &c : map[digits[i]]) {
            tmp += c;
            combinations(tmp, i + 1, digits, map, out);
            tmp.pop_back();
        }
    }
};
