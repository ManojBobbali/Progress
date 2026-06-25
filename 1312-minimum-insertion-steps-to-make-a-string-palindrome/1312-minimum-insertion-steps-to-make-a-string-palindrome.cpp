class Solution {
public:
    int solve(int start, int end, string& s, vector<vector<int>>& dp) {
      
        if (start > end) return 0;
        
        
        if (start == end) return 1;
        
       
        if (dp[start][end] != -1) return dp[start][end];
        
        
        if (s[start] == s[end]) {
            return dp[start][end] = 2 + solve(start + 1, end - 1, s, dp);
        }
        
        
        return dp[start][end] = max(solve(start + 1, end, s, dp), 
                                    solve(start, end - 1, s, dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int> > dp(n,vector(n,-1));
        int x = solve(0,n-1,s,dp);
        return n - x;
        
    }
};