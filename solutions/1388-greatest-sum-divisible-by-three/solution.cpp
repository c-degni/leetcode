class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] % 3 == 0) return nums[0];
            return 0;
        }

        int t = 0;
        vector<int> r1;
        vector<int> r2;
        for (int &i : nums) {
            t += i;
            if (i % 3 == 1) {
                r1.push_back(i);
            } else if (i % 3 == 2) {
                r2.push_back(i);
            }
        }

        int r1s = r1.size();
        int r2s = r2.size();

        if (t % 3 == 1) {
            if (r1s > 0 && r2s > 1) {
                sort(r1.begin(), r1.end());
                sort(r2.begin(), r2.end());
                t -= min(r1[0], r2[0] + r2[1]);
            } else if (r1s > 0) {
                sort(r1.begin(), r1.end());
                t -= r1[0];
            } else if (r2s > 1) {
                sort(r2.begin(), r2.end());
                t -= (r2[0] + r2[1]);
            } else {
                return 0;
            }
        } else if (t % 3 == 2) {
            if (r2s > 0 && r1s > 1) {
                sort(r1.begin(), r1.end());
                sort(r2.begin(), r2.end());
                t -= min(r2[0], r1[0] + r1[1]);
            } else if (r2s > 0) {
                sort(r2.begin(), r2.end());
                t -= r2[0];
            } else if (r1s > 1) {
                sort(r1.begin(), r1.end());
                t -= (r1[0] + r1[1]);
            } else {
                return 0;
            }
        }
        return t;
    }
};
