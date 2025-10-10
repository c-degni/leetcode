class TrieNode {
public:
    TrieNode* children[26];
    bool end;
    TrieNode(bool f = false) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        end = f;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string w) {
        TrieNode* tmp = root;
        for (char &c : w) {
            int idx = c - 'a';
            if (!tmp->children[idx]) {
                tmp->children[idx] = new TrieNode();
            }
            tmp = tmp->children[idx];
        }
        tmp->end = true;
    }
    vector<string> findWordsWithPrefix(string prefix, int limit) {
        vector<string> res;
        TrieNode* tmp = root;
        for (char &c : prefix) {
            int idx = c - 'a';
            if (!tmp->children[idx]) {
                return res;
            }
            tmp = tmp->children[idx];
        }
        // Now at the end of prefix
        collectWords(tmp, prefix, res, limit);
        return res;
    }
private:
    void collectWords(TrieNode* node, string prefix, vector<string> &res, int limit) {
        if (!node || res.size() >= limit) return;
        if (node->end) res.push_back(prefix);
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                prefix += char('a' + i);
                collectWords(node->children[i], prefix, res, limit);
                prefix.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for (string &s : products) t.insert(s);
        string inc = "";
        vector<vector<string>> res;
        for (char &c : searchWord) {
            inc += c;
            res.push_back(t.findWordsWithPrefix(inc, 3));
        }
        return res;
    }
};
