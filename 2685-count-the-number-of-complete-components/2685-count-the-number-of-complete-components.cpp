class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis, int& nodeCount, int& edgeCount) {
        vis[node] = true;
        nodeCount++;
        edgeCount += graph[node].size(); 
        
        for (int child : graph[node]) {
            if (!vis[child]) {
                dfs(child, graph, vis, nodeCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(n, false);
        int completeComponentsCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodeCount = 0;
                int edgeCount = 0;
                
                dfs(i, graph, vis, nodeCount, edgeCount);
                
                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};