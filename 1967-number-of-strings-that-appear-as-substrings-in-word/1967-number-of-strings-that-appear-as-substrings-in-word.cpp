class Solution {
public:
    bool issub(string& s,string &word){
        if (s.empty()) return true;
        if (s.size() > word.size()) return false;
        for(int i = 0; i <= word.size()-s.size();i++){
            int p1 = i;
            int p2 = 0;
            while( p2 < s.size() && word[p1] == s[p2]){
                p1++;
                p2++;
            }
            if(p2 == s.size())return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string s:patterns){
            if(issub(s,word))cnt++;
        }
        return cnt;
    }
};