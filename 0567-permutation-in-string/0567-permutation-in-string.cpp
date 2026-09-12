class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length(),m = s1.length();
        vector<int> v(26,0);
        for(char c : s1){
            v[c - 'a']++;
        }
        for(int i = 0; i <= n-m;i++){
            if(v[s2[i] - 'a']){
                vector<int> temp(26,0);
                for(int k = 0; k < 26;k++){
                    temp[k] = v[k];
                }
                bool found = true;
                for(int j = 0; j < m;j++){
                    if(!temp[s2[i+j] - 'a']){
                        found = false;
                        break;
                    }
                    temp[s2[i+j] - 'a']--;
                }
                if(found)return true;
            }
        }
        return false;
    }
};