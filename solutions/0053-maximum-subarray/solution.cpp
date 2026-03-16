class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0];
        int sum = 0;
        for (int &num : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += num;
            m = max(m, sum);
        }
        return m;
    }
};
