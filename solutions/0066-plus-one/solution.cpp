class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        bool c = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9 && c) {
                res.insert(res.begin(), 0);
                c = true;
            } else if (c) {
                res.insert(res.begin(), digits[i] + 1);
                c = false;
            } else {
                res.insert(res.begin(), digits[i]);
            }
        }
        if (c) res.insert(res.begin(), 1);
        return res;
    }
};
