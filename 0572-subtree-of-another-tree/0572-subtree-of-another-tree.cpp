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
        if(!p || !q)return false;
        if(q->val != p->val)return false;
        return sametree(p->left,q->left) && sametree(p->right,q->right);
    }
    bool dfs(TreeNode* root,TreeNode* subroot){
        if(!root) return false;
        if(root->val == subroot->val){
            if(sametree(root,subroot)) return true;
        }
        return dfs(root->left,subroot) || dfs(root->right,subroot);
   }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
        
    }
};