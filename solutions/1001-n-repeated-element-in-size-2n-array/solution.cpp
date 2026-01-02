class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 2) return nums[0];
        if (nums[0] == nums[n / 2 - 1]) return nums[0];
        int i = 1;
        while (i + n / 2 < n) {
            if (nums[i] == nums[i + n / 2]) return nums[i];
            i++;
        }
        return nums[i];
    }
};
