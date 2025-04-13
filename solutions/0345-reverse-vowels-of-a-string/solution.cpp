class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            char lleft = tolower(s[left]);
            char lright = tolower(s[right]);
            
            if (lleft == 97 || lleft == 101 || lleft == 105 || lleft == 111 || lleft == 117) {
                if (lright == 97 || lright == 101 || lright == 105 || lright == 111 || lright == 117) {
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                } else {
                    right--;
                }
            } else {
                if (lright == 97 || lright == 101 || lright == 105 || lright == 111 || lright == 117) {
                    left++;
                } else {
                    left++;
                    right--;
                }
            }
        }
        return s;
    }
};
