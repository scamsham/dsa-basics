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

class TreeMetrics {
    public:
        int diameter;
        int height;
    
        TreeMetrics(int d, int h){
            this->diameter = d;
            this->height = h;
        }
};

class Solution {
public:
    TreeMetrics findDiameter(TreeNode* root){
        TreeMetrics m(0, 0);
        if(!root){
            m.diameter = 0;
            m.height = 0;
            return m;
        }

        TreeMetrics TL = findDiameter(root->left);
        TreeMetrics TR = findDiameter(root->right);

        m.height = 1 + max(TL.height, TR.height);

        m.diameter = max(TL.height + TR.height, max(TL.diameter, TR.diameter)); 

        return m;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return findDiameter(root).diameter;
    }
};