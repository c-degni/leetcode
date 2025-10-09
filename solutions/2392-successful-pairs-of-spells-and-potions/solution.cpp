class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int ss = spells.size();
        int ps = potions.size();
        vector<int> res(ss);
        std::sort(potions.begin(), potions.end());

        for (int i = 0; i < ss; i++) {
            int l = 0;
            int r = ps - 1;
            int weak = ps;
            while (l <= r) {
                int m = (l + r) / 2;
                long long pr = (long long)spells[i] * potions[m];
                if (pr >= success) { // Know everything to the right of m is valid
                    weak = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
                m = (l + r) / 2;
            }
            res[i] = ps - weak;
        }
        return res;
    }
};
