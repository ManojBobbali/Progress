class Solution {
public:
   const int MAX = 1000001;

    long long nCk(int n, int k) {
        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;

            if (res >= MAX)
                return MAX;
        }

        return res;
    }

    long long countWays(vector<int>& cnt) {

        int total = accumulate(cnt.begin(), cnt.end(), 0);

        long long res = 1;

        for (int x : cnt) {

            res *= nCk(total, x);

            if (res >= MAX)
                return MAX;

            total -= x;
        }

        return res;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        vector<int> halfcount(26,0);
        string mid = "";
        for(int i = 0;i < 26;i++){
            if(count[i]%2)mid+=char('a'+i);
            halfcount[i] = count[i]/2;
        }
        long long total = countWays(halfcount);
        if (total < k)
            return "";
        int positions = n/2;
        string firstpart = "";
        for(int i = 0; i < positions;i++){
            for(int j = 0; j < 26;j++){
                if(halfcount[j] == 0)continue;
                halfcount[j]--;
                long long ways = countWays(halfcount);
                if(k > ways){
                   // cout<<ways<<endl;
                   k -=ways;
                   halfcount[j]++;
                }
                else{
                   // cout<<"adding"<<char('a'+j)<<endl;
                    firstpart +=char('a'+j);
                    break;
                }
            }
        }
        string secondpart = firstpart;
        reverse(secondpart.begin(),secondpart.end());
        return firstpart + mid + secondpart;
    }
};