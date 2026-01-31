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
    void rightSideViewHelper(vector<int> &view, TreeNode* root, int level){
        if(!root){
            return ;
        }
        
        if(level == view.size()){
            view.push_back(root->val);   
        }

        rightSideViewHelper(view, root->right, level + 1);
        rightSideViewHelper(view, root->left, level + 1);

        return ;
    }

    vector<int> rightSideView(TreeNode* root) {
        // we traverse inorder from right to left
        // push to vector on every height increment
       
        vector<int> view;
        if(!root){
            return view;
        }

        rightSideViewHelper(view, root, 0);
        return view;
    }
};