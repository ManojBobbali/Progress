struct TrieNode {
    TrieNode* children[2] = {nullptr, nullptr};
};
class Solution {
public:
    TrieNode* root;

   
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    int getMaxXOR(int num) {
        TrieNode* curr = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit; 
            
            
            if (curr->children[oppositeBit]) {
                maxXOR |= (1 << i); 
                curr = curr->children[oppositeBit];
            } else {
               
                curr = curr->children[bit];
            }
        }
        return maxXOR;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        int globalMax = 0;

      
        for (int num : nums) {
            insert(num);
        }

        for (int num : nums) {
            globalMax = max(globalMax, getMaxXOR(num));
        }

        return globalMax;
    }
};