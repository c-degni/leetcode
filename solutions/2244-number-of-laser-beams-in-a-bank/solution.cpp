class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int i = 0;
        int d = 0;
        int p = 0;
        int a = 0;
        while (i < n) {
            d = 0;
            for (char &c : bank[i]) if (c == '1') d++;
            if (d != 0) {
                a += p * d;
                p = d;
            }
            i++;
        }
        return a;
    }
};
