class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        int score = m * (1 << (n - 1));
        
        
        for (int j = 1; j < n; j++) {
            int countOnes = 0;
            
            for (int i = 0; i < m; i++) {
                
                if (grid[i][j] == grid[i][0]) {
                    countOnes++;
                }
            }
            
           
            int actualOnes = max(countOnes, m - countOnes);
            
           
            score += actualOnes * (1 << (n - 1 - j));
        }
        
        return score;
    }
};