class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<int> dp(n + 1, 0);
        vector<int> temp(n + 1, 0); 
        dp[0] = 1;
        for (int j = 2;j <= n;j++) 
            dp[j] = p[j-1] == '*' && dp[j-2];
        for (int i = 1;i <= m;i++) {
            for (int j = 0;j <= n;j++) { 
                temp[j] = dp[j];
                dp[j] = 0;
            }
            for (int j = 1;j <= n;j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[j] = temp[j-1];
                if (p[j-1] == '*') { 
                    dp[j] |= temp[j] && (p[j-2] == '.' || p[j-2] == s[i-1]);
                    dp[j] |= dp[j-2]; 
                }
            }
        }
        return dp[n];
    }
};