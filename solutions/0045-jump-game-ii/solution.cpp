class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, INT_MAX);
        t[0] = 0;

        for (int i = 0; i < n; i++) {
            int j = i + 1; 
            while (j < n && j < i + nums[i] + 1) {
                t[j] = min(t[j], t[i] + 1);
                j++;
            }
        }

        return t[n - 1];
    }
};
