class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int m = 0;
        int c = 0;

        while (left < right) {
            c = min(height[left], height[right]) * (right - left);
            if (c > m) m = c;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return m;
    }
};
