class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int *p1 = &nums[0];
        int *p2 = &nums[0];
        int *l = p1 + nums.size();
        
        while (p1 < l) {
            // On zero, search for first num with p2
            if (*p1 == 0) {
                while (p2 < l) {
                    if (*p2 != 0) {
                        // Swap p1 and p2 numbers
                        *p1 = *p2;
                        *p2 = 0;
                        break;
                    }  
                    p2++;
                }
                // Set p2 back to p1
                p2 = p1;
            }
            // Increment p1 and p2
            p1++;
            p2++; 
        }
    }
};
