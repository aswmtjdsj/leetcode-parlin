#include "header.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int biu = 1;
        vector<int> ans;
        for(int i = digits.size()-1; i >= 0; i--) {
            if(digits[i] + biu > 9) {
                biu = 1;
                ans.push_back(0);
            }
            else {
                ans.push_back(digits[i] + biu);
                biu = 0;
            }
        }
        if(biu) {
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
}
