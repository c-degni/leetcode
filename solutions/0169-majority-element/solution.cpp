class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = nums[i];
            int t = 1;
            while (i < n && nums[i] == j) {
                if (t > n / 2) return j;
                t++;
                i++;
            }
            i--;
        }
        return 0;
    }
};
