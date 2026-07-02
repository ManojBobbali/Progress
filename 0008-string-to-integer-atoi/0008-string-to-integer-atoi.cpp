class Solution {
public:
    int myAtoi(string s) {
        long long  ans = 0;
        int n = s.length();
        int i = 0;
        int sign = 1;
       while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++; 
        }
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;
            i++;
        }
        return sign * ans; 
    }
};