class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();

        vector<long long> totalshifts(n,0);
        totalshifts[n-1] = shifts[n-1];

        for(int i = n-2; i >=0;i--){
            totalshifts[i] = shifts[i] + totalshifts[i+1];
        }
        for(int i = 0;i < n;i++){
            int x = totalshifts[i]%26;
            s[i] = (s[i] - 'a' + x) % 26 + 'a';
        }
        return s;
    }
    
};