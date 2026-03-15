class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        bool c = false;
        string out = "";
        while (i >= 0 && j >= 0) {
            int sum = (a[i] - '0') + (b[j] - '0');
            if (c) {
                sum++;
                if (sum == 3) {
                    out = "1" + out;
                } else if (sum == 2) {
                    out = "0" + out;
                } else {
                    out = "1" + out;
                    c = false;
                }
            } else {
                if (sum == 2) {
                    out = "0" + out;
                    c = true;
                } else {
                    out = to_string(sum) + out;
                }
            }
            i--;
            j--;
        }

        while (i >= 0) {
            if (c) {
                if ((a[i] - '0') + 1 == 2) {
                    out = "0" + out;
                } else {
                    out = "1" + out;
                    c = false;
                }
            } else {
                out = to_string(a[i] - '0') + out;
            }
            i--;
        }

        while (j >= 0) {
            if (c) {
                if ((b[j] - '0') + 1 == 2) {
                    out = "0" + out;
                } else {
                    out = "1" + out;
                    c = false;
                }
            } else {
                out = to_string(b[j] - '0') + out;
            }
            j--;
        }

        if (c) out = "1" + out;

        return out;
    }
};
