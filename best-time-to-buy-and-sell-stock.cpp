#include <iostream>
#include <vector>

using namespace std;
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int ans = 0;
            int minn = 10000000;
            for(auto idx = prices.begin(); idx != prices.end(); idx++) {
                if(minn > *idx) {
                    minn = *idx;
                }
                if(*idx - minn > ans) {
                    ans = *idx - minn;
                }
            }
            return ans;
        }
};
int main() {

}
