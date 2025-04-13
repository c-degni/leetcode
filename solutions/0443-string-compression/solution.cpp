class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;
        char cur = chars[0];
        int i = 1;
        int idx = 1;
        int range = 1;
        int num = 1; 

        while (i < chars.size()) {
            if (chars[i] == cur) {
                num++;
                if (i == idx) {
                    chars[i] = num + '0';
                } else if (num % 10 == 0) {
                    int tmp = range;
                    range = floor(log10(abs(num))) + 1;
                    if (tmp != range) {
                        idx++;
                        i++;
                    } else {
                        chars.erase(chars.begin() + i);
                        chars[idx]++;
                    }
                    tmp = num;
                    for (int j = 0; j < range; j++) {
                        chars[idx - j] = (tmp % 10) + '0';
                        tmp /= 10;
                    }
                    continue;
                } else {
                    chars.erase(chars.begin() + i);
                    chars[idx]++;
                    continue;
                }
            } else {
                cur = chars[i];
                idx = i + 1;
                num = 1;
                range = 1;
            }
            i++;
        }
        return chars.size();
    }
};
