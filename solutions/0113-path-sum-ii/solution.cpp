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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> p;
        pathSum(root, {}, p, 0, targetSum);
        return p;
    }
private:
    void pathSum(TreeNode* node, vector<int> tmp, vector<vector<int>>& p, int s, int t) {
        if (!node) return;
        s += node->val;
        tmp.push_back(node->val);
        if (!node->left && !node->right && s == t) p.push_back(tmp);
        pathSum(node->left, tmp, p, s, t);
        pathSum(node->right, tmp, p, s, t);
    }
};
