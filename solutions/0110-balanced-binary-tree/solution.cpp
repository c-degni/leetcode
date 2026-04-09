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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        depth(root, res);
        return res;
    }
private:
    int depth(TreeNode* node, bool& res) {
        if (!node || !res) return 0;
        int l = depth(node->left, res);
        int r = depth(node->right, res);
        if (std::abs(l - r) > 1) res = false;
        return 1 + std::max(l, r);
    }
};
