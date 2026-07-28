class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26,0);
        for(int i = 0; i < s.length();i++){
            count[s[i] - 'a']++;
        }
        string sa = "";
        for(int i = 0; i < 26;i++){
            if(count[i] >= 2){
                    int k = count[i]/2;
                    count[i] = count[i]%2;
                    while(k){
                        sa+='a'+i;
                        k--;
                    }
            }
        }
        string temp = sa;
        reverse(sa.begin(),sa.end());
        for(int i = 0; i < 26;i++){
            if(count[i] == 1){
                temp+='a'+i;
                break;
            }
        }
       
        temp +=sa;
        return temp;
    }
};