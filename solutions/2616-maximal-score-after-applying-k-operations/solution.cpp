class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long s = 0;
        multiset<long long> m;
        
        for (int i = 0; i < nums.size(); i++) {
            m.insert(nums[i]);
        }

        while (k > 0) {
            long long v = *m.rbegin();
            s += v;
            m.erase(m.find(v));
            m.insert(ceil(v / double(3)));
            k--;
        }

        return s;
    }
};
