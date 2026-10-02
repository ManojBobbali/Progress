class Solution {
public:
    void generate(int open,int close,int n,string s,vector<string>& result){
        if(s.length() == 2*n){
            result.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            generate(open+1,close,n,s,result);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');

            generate(open,close + 1,n,s,result);
            s.pop_back();
        }
    
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generate(0,0,n,s,result);
        return result;
    }
};