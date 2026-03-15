class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int i = 0;
        while (i < m) {
            if (nums1[i] > nums2[0]) {
                int t = nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = t;
                sort(nums2.begin(), nums2.end());
            }
            i++;
        }

        for (int &j : nums2) {
            nums1[i] = j;
            i++;
        }
    }
};
