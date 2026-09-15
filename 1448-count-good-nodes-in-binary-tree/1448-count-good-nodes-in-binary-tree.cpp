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
    void dfs(TreeNode* root,int max_so_far,int& count){
        if(!root)return;
        if(root->val >= max_so_far)count++;
        dfs(root->left,max(root->val,max_so_far),count);
        dfs(root->right,max(root->val,max_so_far),count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root,INT_MIN,count);
        return count;
    }
};