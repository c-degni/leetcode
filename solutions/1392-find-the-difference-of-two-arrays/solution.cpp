class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1, set2;
        std::vector<std::vector<int>> res = {{},{}};

        for (int &i : nums1) set1.insert(i);
        for (int &i : nums2) set2.insert(i);

        for (int i : set1)
        {
            if (!set2.contains(i)) 
            {
                res[0].push_back(i);
            }
        }

        for (int i : set2)
        {
            if (!set1.contains(i)) 
            {
                res[1].push_back(i);
            }
        }

        return res;
    }
};
