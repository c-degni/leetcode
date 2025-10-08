/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> ps;
        std::stack<TreeNode*> qs;
        bool f = false;
        dfs(root, p, ps, f);
        f = false;
        dfs(root, q, qs, f);

        while (!ps.empty() && !qs.empty()) {
            if (ps.size() > qs.size()) {
                ps.pop();
            } else if (qs.size() > ps.size()) {
                qs.pop();
            } else {
                if (ps.top() == qs.top()) return ps.top();
                ps.pop();
                qs.pop();
            }
        }
        return root;
    }
private:
    void dfs(TreeNode* node, TreeNode* v, std::stack<TreeNode*> &s, bool &found) {
        if (!node) return;
        s.push(node);
        if (s.top() == v) {
            found = true;
            return;
        }
        dfs(node->left, v, s, found);
        dfs(node->right, v, s, found);
        if (!found) s.pop();
    }
};
