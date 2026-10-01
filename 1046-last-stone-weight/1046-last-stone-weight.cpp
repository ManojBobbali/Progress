class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>maxheap(stones.begin(),stones.end());
        int n = stones.size();
        while(maxheap.size()>1){
            int a = maxheap.top();
            maxheap.pop();
            int b = maxheap.top();
            int diff = abs(a-b);
            maxheap.pop();
            if(diff>0)maxheap.push(diff);
           
        }
        if(maxheap.size() == 0)return 0;
        return maxheap.top();
        
    }
};