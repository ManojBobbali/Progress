class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     int n = arr.size();
        if (n == 0) return {}; 
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> numToRank;
        int currentRank = 1;
        
        for (int i = 0; i < n; i++) {
          
            if (numToRank.find(sortedArr[i]) == numToRank.end()) {
                numToRank[sortedArr[i]] = currentRank;
                currentRank++;
            }
        }
        
      
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = numToRank[arr[i]];   
        }
        return result;
    }

};