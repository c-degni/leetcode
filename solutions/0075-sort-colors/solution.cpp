class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        bool swapped;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (nums[i] > nums[j]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    swapped = true;
                }
            }
            if (!swapped) return;
        }
    }
};
