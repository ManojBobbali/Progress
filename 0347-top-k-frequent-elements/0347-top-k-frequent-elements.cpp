class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num:nums)mp[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        int cnt = 1;
        for(auto m : mp){
           pq.push({m.second,m.first});
           if(pq.size() > k){
              pq.pop();
           }
        }
        vector<int> res;
        while(!pq.empty()){
           res.push_back(pq.top().second);
           pq.pop();
        }
        return res; 
    }
};