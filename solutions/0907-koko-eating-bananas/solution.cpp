class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // h >= piles.size()
        // 1 <= k <= max pile
        int maxPile = *(std::max_element(piles.begin(), piles.end()));
        int l = 1;
        int r = maxPile;
        int ml = r;
        while (l <= r) {
            int m = (l + r) / 2;
            long s = 0;
            for (int &i : piles) {
                s += std::ceil(double(i) / m);
            }
            if (s <= h) {
                ml = std::min(m, ml);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ml;
    }
};
