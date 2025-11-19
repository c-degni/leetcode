class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        bool f = true;
        while (f) {
            sort(nums.begin(), nums.end());
            // binary search for original
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int m = (right - left) / 2 + left;
                if (nums[m] == original) {
                    original *= 2;
                    break;
                } else if (nums[m] < original) {
                    left = m + 1;
                } else {
                    right = m - 1;
                }   
            }
            if (left > right) f = false;
        }
        return original;
    }
};
