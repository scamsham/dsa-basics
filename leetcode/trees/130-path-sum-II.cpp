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
    void findAllPaths(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &paths){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            if(targetSum - root->val == 0){
                path.push_back(root->val);
                paths.push_back(path);
                // Backtracking: Undo the choice to keep the path clean for the next branch.
                path.pop_back();
            }
            return ;
        }

        path.push_back(root->val);

        findAllPaths(root->left, targetSum - root->val, path, paths);
        findAllPaths(root->right, targetSum - root->val, path, paths);
        
        // Backtracking: Undo the choice to keep the path clean for the next branch.
        path.pop_back();
        return ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        findAllPaths(root, targetSum, path, paths);

        return paths;
    }
};