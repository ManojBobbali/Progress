class Solution {
public:
    char processStr(string s, long long k) {
        
        vector<long long> l;
        l.push_back(0);

        for(int i = 0; i < s.length(); i++){

            long long n = l.back();

            if(s[i] == '*'){
                l.push_back(max(0LL, n - 1));
            }
            else if(s[i] == '#'){
                l.push_back(2 * n);
            }
            else if(s[i] == '%'){
                l.push_back(n);
            }
            else{
                l.push_back(n + 1);
            }
        }
        if (k >= l.back()) return '.';
        for(int i=s.length()-1;i>=0;i--)
        {
            long long prevLen=l[i];
            long long currLen=l[i+1];

            if(s[i]=='#')
            {
                if(prevLen>0)
                    k%=prevLen;
            }
            else if(s[i]=='%')
            {
                if(prevLen>0)
                    k=prevLen-1-k;
            }
            else if(s[i]=='*')
            {
                if(k == currLen)
                return '.';
            }
            else
            {
                if(k==currLen-1)
                    return s[i];
            }
        } 
        return '.';      
    }
    
};