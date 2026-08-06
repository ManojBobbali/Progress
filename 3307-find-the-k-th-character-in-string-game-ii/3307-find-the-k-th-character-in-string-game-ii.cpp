class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int m = operations.size();
        vector<long long> len(m + 1);
        len[0] = 1;
        for (int i = 0; i < m; i++) {
            len[i + 1] = min((long long)2e18, len[i] * 2);
        }

        int shift = 0;
        for(int i = m-1;i >=0;i--){
            long long half = len[i];
            if(k > len[i]){
                k = k - len[i];
                if(operations[i] == 1)shift++;
            }
        }
        return char('a' + (shift % 26));
    }
};