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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> lv1;
        vector<int> lv2;
        lvs(root1, lv1);
        lvs(root2, lv2);
        return lv1 == lv2;
    }
private:
    void lvs(TreeNode* node, vector<int> &v) {
        if (!node) return;
        lvs(node->left, v);
        lvs(node->right, v);
        if (!node->left && !node->right) v.push_back(node->val);
    }
};
