class Solution {
public:
    string reverseWords(string s) {
       reverse(s.begin(),s.end());
       int l = 0;
       int n = s.length();
       for(int i = 0; i < n;i++){
           if(s[i]!= ' '){
              if(l != 0) s[l++] = ' '; 
              int j = l;
           
           while(i < n && s[i]!=' '){
                s[l++] = s[i++];
           }
           reverse(s.begin() + j,s.begin()+l);
           }
       }
       s.resize(l);
       return s;
    }
};