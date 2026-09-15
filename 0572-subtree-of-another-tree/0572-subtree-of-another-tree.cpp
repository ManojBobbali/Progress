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
    bool sametree(TreeNode* p,TreeNode* q){
        if(!p && !q)return true;
        if(!p)return false;
        if(!q)return false;
        if(q->val != p->val)return false;
        return sametree(p->left,q->left) && sametree(p->right,q->right);
    }
    void dfs(TreeNode* root,TreeNode* subroot,bool& found){
        if(!root) return;
        if(root->val == subroot->val){
            if(!found) found = sametree(root,subroot);
        }
        dfs(root->left,subroot,found);
        dfs(root->right,subroot,found);
   }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool found = false;
        dfs(root,subRoot,found);
        return found;
    }
};