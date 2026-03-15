class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        /*
         * step[i - 1] jump + current jump
         * step[i - 2] jump + current jump
         * step[i - 3] jump + current jump
         * min cost at i is min of the above three options
         */
         
        int steps[n + 1];
        steps[0] = 0;
        steps[1] = steps[0] + costs[0] + 1;
        if (n >= 2) {
            steps[2] = min(
                steps[1] + costs[1] + 1,
                costs[1] + 4
            );
        }
        for (int i = 3; i < n + 1; i++) {
            steps[i] = min(
                steps[i - 1] + costs[i - 1] + 1,
                min(
                    steps[i - 2] + costs[i - 1] + 4,
                    steps[i - 3] + costs[i - 1] + 9
                )
            );
        }
        return steps[n];
    }
};
