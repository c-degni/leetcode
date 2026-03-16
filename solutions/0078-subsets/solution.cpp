class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;    
        rec(0, nums, {}, out);
        return out;
    }
private:
    void rec(int index, vector<int>& nums, vector<int> tmp, vector<vector<int>>& out) {
        out.push_back(tmp);

        for (int i = index; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            rec(i + 1, nums, tmp, out);
            tmp.pop_back();
        }
    }
};
