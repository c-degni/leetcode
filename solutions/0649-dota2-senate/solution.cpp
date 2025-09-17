class Solution {
public:
    string predictPartyVictory(string senate) {
        int s = senate.length();
        std::queue<int> d;
        std::queue<int> r;

        for (int i = 0; i < s; i++) {
            if (senate[i] == 'D') d.push(i);
            else r.push(i);
        }

        while (!d.empty() && !r.empty()) {
            int cd = d.front();
            int cr = r.front();
            r.pop();
            d.pop();
            if (cd < cr) d.push(cd + s);
            else r.push(cr + s);
        }

        if (r.empty()) return "Dire";
        return "Radiant";
    }
};
