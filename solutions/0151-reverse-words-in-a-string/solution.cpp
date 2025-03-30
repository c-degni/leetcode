class Solution {
public:
    string reverseWords(string s) {
        // Push all words to stack
        string w = "";
        int l = s.length();
        stack<string> st;

        for (int i = 0; i < l; i++) {
            if (s[i] == ' ') {
                if (!w.empty()) st.push(w);
                w = "";
            } else {
                w += s[i];
            }

            if (i == l - 1 && !w.empty()) st.push(w);
        }
        // Create return by popping words and adding spaces between
        w = "";
        int sl = st.size();
        
        for (int i = 0; i < sl; i++) {
            w += st.top();
            st.pop();
            if (i == sl - 1) continue;
            w += ' ';
        }
        return w;
    }
};
