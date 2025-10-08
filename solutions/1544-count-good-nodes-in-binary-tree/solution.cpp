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
    int goodNodes(TreeNode* root) {
        int good = 0;
        gn(root, INT_MIN, good);
        return good;
    }
private:
    void gn(TreeNode* node, int m, int &g) {
        if (!node) return;
        if (node->val >= m) {
            m = std::max(node->val, m);
            g++;
        }
        gn(node->left, m, g);
        gn(node->right, m, g);
    }
};
