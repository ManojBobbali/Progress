class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        int prefsum  = 0;
        int n = arr.size();
        vector<pair<int,int>> v;
        vector<int> pref(n+1,INT_MAX);
        vector<int> suf(n,INT_MAX);
        for(int i = 0; i < arr.size();i++){
            prefsum +=arr[i];

            if(prefsum == target){
               pref[i+1] = min(pref[i+1],i+1);
               v.push_back({0,i});
            }
            if(mp.find(prefsum - target) != mp.end()){
                int start = mp[prefsum - target] + 1;
                pref[i+1] = min(pref[i+1],i - start + 1);
                suf[start] = min(suf[i],i - start + 1);
                v.push_back({start,i});
            }
            mp[prefsum] = i;
        }
        int minsum = INT_MAX;
        /*for(int i = 0; i < v.size();i++){
            int start = v[i].first;
            int end = v[i].second;
            for(int j = i+1;j < v.size();j++){
                if((v[j].first  <= end && v[j].first >= start) || (v[j].second <= end && v[j].second >= start)){
                    continue;
                }
                minsum = min(end - start + v[j].second - v[j].first + 2,minsum);
            }
        }*/
        for(int i = 1; i < n;i++){
            pref[i] = min(pref[i],pref[i-1]);
        }
        for(int i = n-2;i >=0;i--){
            suf[i] = min(suf[i+1],suf[i]);
        }
        for(int i = 0; i < n;i++){
            if(pref[i] != INT_MAX && suf[i] != INT_MAX){
                minsum = min(minsum,pref[i] + suf[i]);
            }
        }
        if(minsum == INT_MAX)return -1;
        return minsum;
    }
};