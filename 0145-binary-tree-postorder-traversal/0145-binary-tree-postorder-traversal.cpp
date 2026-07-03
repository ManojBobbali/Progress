class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr; 
        
        while (curr != nullptr || !st.empty()) {
          
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } 
            else {
                TreeNode* peekNode = st.top();
                
                
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    curr = peekNode->right;
                } 
                else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode; 
                    st.pop();
                }
            }
        }
        
        return result;
    }
};