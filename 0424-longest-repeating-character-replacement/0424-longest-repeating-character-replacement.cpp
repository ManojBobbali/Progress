class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0,j = 0;
        int n = s.length();
        int len = 0,max_len = 0;
        vector<int> v(26,0);
        int max_rep = 0;
        while(i < n){
            v[s[i] - 'A']++;
            max_rep = max(max_rep,v[s[i] - 'A']);
            while(j < n && ((i - j + 1) - max_rep > k)){
                v[s[j] - 'A']--;
                j++;
            }
            max_len = max(max_len,i - j + 1);
            i++;
        }
        return max_len;
    }
};