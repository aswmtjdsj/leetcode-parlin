#include "header.h"

class Solution {
public:
    int jump(int A[], int n) {
        int * dp = new int[n];
        int inf = 100000000;
        fill(dp, dp + n, inf);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = min(n - 1, i + A[i]); j > i; j--) {
                if(dp[j] > dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                }
                else {
                    break;
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
}
