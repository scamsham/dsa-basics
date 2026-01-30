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
    bool isMirror(TreeNode* leftTree, TreeNode* rightTree){
        if(!leftTree && !rightTree){
            return true;
        }

        if(!leftTree || !rightTree || leftTree->val != rightTree->val){
            return false;
        }

        return isMirror(leftTree->left, rightTree->right) && isMirror(leftTree->right, rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return isMirror(root->left, root->right);
    }
};