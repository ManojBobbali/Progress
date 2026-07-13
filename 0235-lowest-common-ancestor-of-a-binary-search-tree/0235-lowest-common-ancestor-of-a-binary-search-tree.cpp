/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* node,int curr_depth,TreeNode* par,unordered_map<TreeNode*,int>& mp,unordered_map<TreeNode*,TreeNode*>& parent){
        if(!node)return;
        mp[node] = curr_depth;
        parent[node] = par;
        dfs(node->left,curr_depth+1,node,mp,parent);
        dfs(node->right,curr_depth+1,node,mp,parent);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,int> mp;
        unordered_map<TreeNode*,TreeNode*> parent;
        dfs(root,0,nullptr,mp,parent);
       
            if(mp[p] > mp[q]){
                while(mp[p] != mp[q]) p = parent[p];
            }
            else{
                while(mp[p] != mp[q]) q = parent[q];
            }

            while(p!=q){
                p = parent[p];
                q = parent[q];
            }
            return q;
        }
    
};