class Solution {
public:

    long long modPow(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1)
                res=res*a%1000000007;

            a=a*a%1000000007;
            b>>=1;
        }
        return res;
    }


    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD=1e9+7;

        int n=s.size();

        vector<long long> prefSum(n);
        vector<long long> prefNum(n);
        vector<int> cnt(n);


        for(int i=0;i<n;i++){

            int digit=s[i]-'0';

            if(i){
                prefSum[i]=prefSum[i-1];
                prefNum[i]=prefNum[i-1];
                cnt[i]=cnt[i-1];
            }

            if(digit){
                prefSum[i]+=digit;

                prefNum[i]=(prefNum[i]*10+digit)%MOD;

                cnt[i]++;
            }
        }


        vector<int> ans;


        for(auto &q:queries){

            int l=q[0];
            int r=q[1];


            long long sum=prefSum[r];

            if(l)
                sum-=prefSum[l-1];


            if(sum==0){
                ans.push_back(0);
                continue;
            }


            long long num=prefNum[r];


            if(l){

                long long before=prefNum[l-1];

                int digitsAfter=cnt[r]-cnt[l-1];

                num=(num-before*modPow(10,digitsAfter))%MOD;

            }
            if(num<0)
                num+=MOD;

            ans.push_back((num*sum)%MOD);

        }
        return ans;
    }
};