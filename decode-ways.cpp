#include "header.h"

class Solution {
    public:
        int numDecodings(string s) {
            if(s.size() == 0) {
                return 0;
            }
            int dp[10000];
            int n = s.size();

            fill(dp, dp + n + 1, 0);
            dp[0] = 1;
            for(int i = 1; i <= n; i++) {
                if(i > 1) {
                    int a = s[i-2] - '0';
                    a = a * 10 + s[i-1] - '0';
                    if(a > 9 && a < 27) {
                        dp[i] += dp[i-2];
                    }
                }
                if(s[i-1] >= '1' && s[i-1] <= '9') {
                    dp[i] += dp[i-1];
                }
            }
            return dp[n];
        }
};

int main(int argc, char ** argv) {
    Solution a;
    cout << a.numDecodings(argv[1]) << endl;
}
