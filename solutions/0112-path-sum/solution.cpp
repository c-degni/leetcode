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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return rec(root, 0, targetSum);
    }
private:
    bool rec(TreeNode* node, int s, int t) {
        if (!node) return false;
        s += node->val;
        if (!node->left && !node->right) return s == t;
        if (!node->left) return rec(node->right, s, t);
        if (!node->right) return rec(node->left, s, t);
        return rec(node->left, s, t) || rec(node->right, s, t);
    }
};
