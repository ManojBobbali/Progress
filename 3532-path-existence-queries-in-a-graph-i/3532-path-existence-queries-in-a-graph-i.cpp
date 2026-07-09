class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);
        int currentGroup = 0;
        group[0] = currentGroup;
        
        for (int i = 1; i < n; i++) {
            
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentGroup++; 
            }
            group[i] = currentGroup;
        }
        
       
        vector<bool> answer;
        answer.reserve(queries.size()); 
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            
            if (group[u] == group[v]) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }
        
        return answer;
    }
};