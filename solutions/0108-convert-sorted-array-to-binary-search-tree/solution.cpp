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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }
private:
    TreeNode* build(int left, int right, vector<int>& nums) {
        if (left > right) return nullptr;
        int m = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = build(left, m - 1, nums);
        node->right = build(m + 1, right, nums);
        return node;
    }
};
