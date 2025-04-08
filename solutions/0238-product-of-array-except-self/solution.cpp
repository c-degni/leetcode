class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // Populate ans with prefix products
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = 1;
                continue;
            }
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Apply postfix products to prefixes to generate true ans
        int c = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                c *= nums[i];
                continue;
            }
            ans[i] *= c;
            c *= nums[i];
        }
        return ans; 
    }
};
