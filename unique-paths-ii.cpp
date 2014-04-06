#include "header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int dp[105][105];
        int m = obstacleGrid.size();
        if(m==0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(obstacleGrid[i-1][j-1] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    if( i == 1 && j == 1) {
                        dp[i][j] = 1;
                    }
                    else if(i == 1) {
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(j == 1) {
                        dp[i][j] = dp[i-1][j];
                    }
                    else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
}
