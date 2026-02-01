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

class TNHelper{
    public:
        bool isBalanced;
        int height;
        TNHelper() : isBalanced(true), height(0) {}

        TNHelper(bool isB, int h){
            this->isBalanced = isB;
            this->height = h;
        }
};

class Solution {
public:
    TNHelper isBalancedHelper(TreeNode* root){
        TNHelper tnh;
        if(!root){
            tnh.isBalanced = true;
            tnh.height = 0;

            return tnh;
        }

        TNHelper leftTree = isBalancedHelper(root->left);
        TNHelper rightTree = isBalancedHelper(root->right);

        tnh.height = 1 + max(leftTree.height, rightTree.height);
        tnh.isBalanced = abs(leftTree.height - rightTree.height) <= 1 && leftTree.isBalanced && rightTree.isBalanced;

        return tnh;
    }


    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).isBalanced;
    }
};