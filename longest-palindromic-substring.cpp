class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[1005][1005];
        //dp.resize(n);
        
        int ans = 0, ans_i = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                if(i==0) dp[j][j+i] = true;
                else if(i == 1) {
                    if(s[j] == s[j+i]) dp[j][j+i] = true;
                    else dp[j][j+i] = false;
                }
                else if(s[j] == s[j+i] && dp[j+1][j+i-1] == true) dp[j][j+i] = true;
                else dp[j][j+i] = false;
                if(dp[j][j+i] == true && i + 1 > ans) {
                    ans = i + 1;
                    ans_i = j;
                }
            }
        }
        return s.substr(ans_i, ans);
    }
};
