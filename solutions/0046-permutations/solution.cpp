class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        for (int &num : nums) {
            set<int> v;
            vector<vector<int>> tmp; 
            per(num, v, nums, tmp); // tmp = all permutations with num as root
            res.insert(res.end(), tmp.begin(), tmp.end()); // append tmp to result
        }
        return res;
    }
private:
    void per(int num, set<int> visited, vector<int>& nums, vector<vector<int>>& res, vector<int> tmp = {}) {
        if (visited.count(num) > 0) return;

        visited.insert(num);
        tmp.push_back(num);
        
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int &num : nums) {
            per(num, visited, nums, res, tmp);
        }
    }   
};
