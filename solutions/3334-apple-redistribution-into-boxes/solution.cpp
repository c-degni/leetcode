class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;
        for (int &a : apple) apples += a;
        sort(capacity.begin(), capacity.end(), greater<int>());
        int i = 0;
        while (apples > 0) {
            i++;
            apples -= capacity[i - 1];
        }
        return i;
    }
};
