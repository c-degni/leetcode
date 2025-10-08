/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int m = 0;
        dfs(root, 'L', 0, m);
        return m;
    }
private:
    void dfs(TreeNode* node, char dir, int c, int &m) {
        if (!node) return;
        if (dir == 'L') {
            if (node->left) {
                c++;
                m = std::max(c, m);
                dfs(node->left, 'R', c, m);
            }
            dfs(node->right, 'L', 1, m);
        } else if (dir == 'R') {
            if (node->right) {
                c++;
                m = std::max(c, m);
                dfs(node->right, 'L', c, m);
            }
            dfs(node->left, 'R', 1, m);
        }
    }
};
