class Solution {
public:
    bool cv(string &s) {
        if (s.empty()) return false;
        for (char &c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }

    bool bv(string &s) {
        return s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant";
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<int> m;
        for (int i = 0; i < code.size(); i++) {
            if (cv(code[i]) && bv(businessLine[i]) && isActive[i]) {
                m.push_back(i);
            }
        }

        sort(m.begin(), m.end(), [businessLine, code](const int &a, const int &b) {
            if (businessLine[a] == businessLine[b]) {
                return code[a] < code[b];
            }
            return businessLine[a] < businessLine[b];
        });
        vector<string> g;
        for (int &i : m) g.push_back(code[i]);
        return g;
    }
};
