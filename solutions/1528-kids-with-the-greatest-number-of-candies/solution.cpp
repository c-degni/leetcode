class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, false);
        int g = *max_element(candies.begin(), candies.end());
    
        for (int i = 0; i < n; i++) if (candies[i] + extraCandies >= g) res[i] = true; 
        return res;
    }
};
