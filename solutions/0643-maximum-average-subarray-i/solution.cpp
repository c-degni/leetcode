class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double s = 0;
        if (n == k) {
            for (int i = 0; i < n; i++) {
                s += nums[i];
            }
            return s / k;
        }

        double m = INT_MIN;
        int i = 0;
        while (i + k <= n) {
            if (i == 0) {
                for (int j = i; j < i + k; j++) {
                    s += nums[j];
                }
            } else {
                s = s + nums[i + k - 1] - nums[i - 1];
            }
            if (s / k > m) m = s / k;
            i++;
        }
        return m;
    }
};
