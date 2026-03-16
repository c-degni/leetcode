class Solution {
public:
    double myPow(double x, int n) {
        if (!n || x == 1 || x == -1 && !(n % 2)) return 1;
        if (x == -1 && n % 2) return -1;
        double r = 1;
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                if (r * x >= numeric_limits<double>::max()) return 0.0;
                r *= x;
            }
        } else {
            unsigned int t = (unsigned int)((double)n * -1);
            for (unsigned int i = 0; i < t; i++) {
                if (x > 0 && r * x <= numeric_limits<double>::min()) return 0.0;
                r *= (1 / x);
            }
        }
        return r;
    }
};
