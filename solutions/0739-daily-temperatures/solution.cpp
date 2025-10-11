class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int s = temperatures.size();
        std::stack<pair<int, int>> st; // ith [idx, temp]
        vector<int> r(s,0);
        for (int i = 0; i < s; i++) {
            int tmp = temperatures[i]; 
            while (!st.empty() && tmp > st.top().second) {
                int idx = st.top().first;
                st.pop();
                r[idx] = i - idx;
            }
            st.push(make_pair(i, tmp));
        }
        return r;
    }
};
