class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int lastNum = nums[0];

        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == lastNum) {
                nums.erase(nums.begin() + i);
            } else {
                lastNum = nums[i];
                i++;
            }
        }

        return nums.size();
    }
};
