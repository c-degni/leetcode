class TrieNode {
public:
    bool end;
    TrieNode* children[26];

    TrieNode(bool e) {
        end = e;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(false);
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        for (char &c : word) {
            int idx = c - 'a';
            if (!tmp->children[idx]) {
                tmp->children[idx] = new TrieNode(false);
            }
            tmp = tmp->children[idx];
        }
        tmp->end = true;
    }
    
    bool search(string word) {
        TrieNode* tmp = root;
        for (char &c : word) {
            int idx = c - 'a';
            if (!tmp->children[idx]) {
                return false;
            }
            tmp = tmp->children[idx];
        }
        return tmp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for (char &c : prefix) {
            int idx = c - 'a';
            if (!tmp->children[idx]) {
                return false;
            }
            tmp = tmp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
