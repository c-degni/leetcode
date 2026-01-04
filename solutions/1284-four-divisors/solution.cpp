class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int a = 0;
        for (int &num : nums) {
            if (num < 6) continue;
            int t = num + 1;
            int c = 0;
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    if (i * i == num) {
                        t += i;
                        c++;
                    } else {
                        t += i + num / i;
                        c += 2;
                    }
                }
                if (c > 2) break;
            }
            if (c == 2) a += t;
        }
        return a;
    }
};
