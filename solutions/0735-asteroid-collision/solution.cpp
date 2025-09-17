class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> st;
        for (int &a : asteroids) {
            while (!st.empty() && a < 0 && st.top() > 0) {
                int d = a + st.top();

                if (d < 0) { // Incoming asteroid wins
                    st.pop();
                } else if (d > 0) { // Incoming asteroid loses
                    a = 0;
                } else { // Both asteroids destroyed
                    st.pop();
                    a = 0;
                }
            }

            if (a != 0) {
                st.push(a);
            }
        }

        std::vector<int> res;
        while (!st.empty()) {
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};
