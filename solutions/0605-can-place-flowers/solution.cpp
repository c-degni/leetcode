class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int f = 0;
        int s = flowerbed.size();

        if (s == 1) {
            if (flowerbed[0] == 0) f++;
            return f >= n;
        }

        for (int i = 0; i < s; i++) {
            if (i == 0) {
                if (s > 1 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    f++;
                }
            } else if (i == s - 1) {
                if (s > 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0) f++;
            } else if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                f++;
            }
            if (f >= n) return true;
        }

        return false;
    }
};
