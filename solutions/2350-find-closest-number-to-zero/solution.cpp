class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        for (int &num : nums) {
            if (abs(num) - 0 == abs(res) - 0) {
                res = max(num, res);
            } else if (abs(num) - 0 < abs(res) - 0) {
                res = num;
            }
        }
        return res;
    }
};
