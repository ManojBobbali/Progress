class Solution {
public:
    const long long MOD = 1e9 + 7;
    int solve(vector<vector<int>>& dp,int hat,int mask,int totalmask,vector<vector<int>>& ppl){
        if(mask == totalmask)return 1;
        if(hat > 40)return 0;
        if(dp[hat][mask]!= -1)return dp[hat][mask];
        int notake = solve(dp,hat+1,mask,totalmask,ppl);
        for(auto p : ppl[hat]){
            int take = 0;
            if((mask & (1<<p)) == 0){
                take = solve(dp,hat+1,mask|(1<<p),totalmask,ppl);
            }
            notake += take;
            notake%= MOD;
        }
        return dp[hat][mask] = notake;  
    }
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> ppl(41);
        for(int i = 0 ; i < hats.size() ; i++){
            for(int j = 0 ; j < hats[i].size() ; j++){
                ppl[hats[i][j]].push_back(i);
            }
        }
        int n = hats.size();
        vector<vector<int>> dp(41,vector<int>(1<<n,-1));
        return solve(dp,1,0,(1<<n) - 1,ppl);
    }
};