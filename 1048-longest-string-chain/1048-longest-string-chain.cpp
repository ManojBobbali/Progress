class Solution {
public:
    bool ispred(string a,string b){
            if(b.length() > a.length())swap(a,b);
            if(a.length() != b.length() + 1)return false;
            int i = 0;
            int j = 0;
            while(j < b.length() && i < a.length()){
                if(b[j] == a[i]){
                    j++;
                    i++;
                }
                else i++;
            }
            if(j == b.length())return true;
            return false; 
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
        [](string& a, string& b){
            return a.size() < b.size();
        });
        vector<int> dp(n,1);
        for(int i = 0; i < n;i++){
            for(int j = 0; j < i;j++){
                if(ispred(words[i],words[j])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};