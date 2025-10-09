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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        } else if (root->val == key) {
            TreeNode* rc = root->right;
            if (!rc) {
                rc = root->left;
                delete root;
                return rc;
            }
            TreeNode* tmp = rc;
            while (tmp->left) tmp = tmp->left;
            tmp->left = root->left;
            delete root;
            return rc;
        } else {
            TreeNode* p = root;
            TreeNode* tra = root;
            while (tra) {
                if (tra->left && key < tra->val) {
                    p = tra;
                    tra = tra->left;
                }  else if (tra->right && key > tra->val) {
                    p = tra;
                    tra = tra->right;
                } else if (tra->val == key) {
                    break;
                } else { // Key not found
                    return root;
                }
            }
            if (p->left && p->left->val == key) {
                TreeNode* rc = p->left->right;
                TreeNode* tmp = rc;
                if (!rc) {
                    rc = p->left->left;
                    TreeNode* tmp = p->left;
                    p->left = rc;
                    delete tmp;
                    return root;
                }
                while (tmp->left) tmp = tmp->left;
                tmp->left = p->left->left;
                delete p->left;
                p->left = rc;
            } else if (p->right && p->right->val == key) {
                TreeNode* rc = p->right->right;
                TreeNode* tmp = rc;
                if (!rc) {
                    rc = p->right->left;
                    TreeNode* tmp = p->right;
                    p->right = rc;
                    delete tmp;
                    return root;
                }
                while (tmp->left) tmp = tmp->left;
                tmp->left = p->right->left;
                delete p->right;
                p->right = rc;
            }
        }
        return root;
    }
};
