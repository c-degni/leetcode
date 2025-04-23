class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Sliding window of increaing size until more 0s than k have been found
        // Left shrink window until 0s are less than k and keep going
        // Keep track of max window size
        // Loop while right is less than nums len but stop if right is nums len - 1
        int n = nums.size();
        if (n == k) return k;
        int m = 0;
        int w = 1;
        int z = 0;
        int left = 0;
        int right = 0;
        if (nums[right] == 0) z++;

        while (right < n - 1) {
            if (z <= k) {
                right++;
                w++;
                if (nums[right] == 0) z++;
                if (z <= k) m = max(w,  m);
            } else {
                if (nums[left] == 0) z--;
                left++;
                w--;
            }
        }
        return m;
    }
};
