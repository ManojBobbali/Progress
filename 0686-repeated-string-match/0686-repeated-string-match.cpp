class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    
        vector<bool> present(26, false);
        for (char c : a)
            present[c - 'a'] = true;

        for (char c : b) {
            if (!present[c - 'a'])
                return -1;
        }

        string cur = "";
        int cnt = 0;

        
        while (cur.size() < b.size()) {
            cur += a;
            cnt++;
        }

       
        if (cur.find(b) != string::npos)
            return cnt;

      
        cur += a;
        cnt++;

        if (cur.find(b) != string::npos)
            return cnt;

        return -1;
    }
};