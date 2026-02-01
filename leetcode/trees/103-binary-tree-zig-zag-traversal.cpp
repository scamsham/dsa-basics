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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        // pushed to signify end of each level
        q.push(NULL);

        bool reverseOrder = false;    

        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            
            if(f == NULL){
                // end of a level
                if(reverseOrder){
                    reverse(level.begin(), level.end());
                }
                result.push_back(level);
                level.clear();
                reverseOrder = !reverseOrder;

                if(q.empty()){
                    // if queue is empty
                    return result;
                }else{
                    // don't forget this
                    // if queue is not empty, we need to push NULL to signify end of level
                    q.push(NULL);
                }
            }else{
                cout<<f->val<<" ";
                // push it to the level
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