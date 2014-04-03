#include "header.h"
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // Note: The Solution object is instantiated only once and is reused by each test case.

            int ans = 0;
            if(prices.size() <= 1) {
                return 0;
            }
            for( int i = 0; i < prices.size() -1; i++){
                if( prices[i+1] > prices[i]) {
                    ans += prices[i+1] - prices[i];
                }
            }
            return ans;
        }
};

int main() {
}
