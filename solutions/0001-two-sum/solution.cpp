class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target && j != i)
                {
                    ans = {i, j};
                    break;
                }
            }
        }
        return ans;
    }
};
