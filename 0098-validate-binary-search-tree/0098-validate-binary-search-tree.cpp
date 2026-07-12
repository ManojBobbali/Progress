class Solution {
public:
    bool validate(TreeNode* node, long long min_val, long long max_val) {
      
        if (!node) return true;

     
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

       
        return validate(node->left, min_val, node->val) && 
               validate(node->right, node->val, max_val);
    }

    bool isValidBST(TreeNode* root) {
       
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};