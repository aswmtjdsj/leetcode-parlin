#include "header.h"

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int dp[1000][1000];
            int l1 = word1.size(), l2 = word2.size();
            // dp array with index meaning length of object and original string
            for(int i = 0; i <= l1; i++) { // cost it takes to convert ori-str to new empty-str
                dp[i][0] = i;
            }
            for(int j = 0; j <= l2; j++) { // cost it takes to convert empty-ori-str to obj-str
                dp[0][j] = j;
            }
            for(int i = 1; i <= l1; i++) {
                for(int j = 1; j <= l2; j++) {
                    int cost = 0;
                    if(word1[i-1] != word2[j-1]) { // here means index
                        cost = 1;
                    }
                    dp[i][j] = min( dp[i-1][j] + 1, // delete, meaning if we can go to this status, then how could we get to another status via it
                            min(dp[i][j-1] + 1, // insert
                                dp[i-1][j-1] + cost) // replace
                            );
                }
            }
            return dp[l1][l2];
        }
};

int main() {
}
