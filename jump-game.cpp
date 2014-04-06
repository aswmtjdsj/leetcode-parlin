#include "header.h"

class Solution {
public:
    bool canJump(int A[], int n) {
        bool dp[100000];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            if(dp[i]) {
                for(int j = min(n - 1, i + A[i]); j > i; j--) {
                    if(dp[j]) {
                        break;
                    }
                    else {
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
}
