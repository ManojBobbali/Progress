class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = 1;

        if (mp.count(1)) {
            ans = max(ans, (mp[1] % 2) ? mp[1] : mp[1] - 1);
        }

        for (auto &[start, f] : mp) {

            if (start == 1) continue;

            long long x = start;
            int len = 0;

            while (x <= 31622 && mp[x] >= 2 && mp.count(x * x)) {
                len += 2;
                x = x * x;
            }

            if (mp.count(x))
                len++;

            ans = max(ans, len);
        }
        return ans;
    }
};