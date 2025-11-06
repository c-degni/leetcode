class Solution {
public:
    int strStr(string haystack, string needle) {
        // If needle is not in haystack, return -1
        // Else return index of first letter of needle in haystack

        // haystack: aadsadbutsad
        // needle: sad

        int i = 0;
        int k = needle.size();
        int n = haystack.size();
        while (i + k <= n) {
            if (needle == haystack.substr(i, k)) return i;
            i++;
        }
        return -1;
    }
};
