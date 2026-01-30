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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        vector<int> level;

        if(!root){
            return result;
        }

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            
            if(f == NULL){
                if(!level.empty()){
                    result.push_back(level);
                    level.clear();
                }
                
                if(!q.empty()){ 
                    q.push(NULL);
                }
                else{
                    reverse(result.begin(), result.end());
                    return result;
                }
            }else{
                level.push_back(f->val);
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }

        }
        return result;
    }
};