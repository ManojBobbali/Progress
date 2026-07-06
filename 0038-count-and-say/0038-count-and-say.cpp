class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if(n == 1)return res;
        for(int i = 1; i < n;i++){
            int s = res.length();
            int count = 1;
            string current = "";
            for(int j = 1; j < s;j++){
               if(res[j-1] == res[j])count++;
               else{
                current += to_string(count) + res[j-1];
                count = 1;
               }
            }
            current += to_string(count) + res.back();
            res = current;
        }
        return res;
    }
};