#include "header.h"

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.size() == 0) {
                return "";
            }
            else {
                string ans = strs[0];
                for(int i = 1; i < strs.size(); i++) {
                    for(int j = 0; j < strs[i].size(); j++) {
                        if(strs[i][j] != ans[j]) {
                            ans = ans.substr(0, j);
                            break;
                        }
                    }
                    if(ans.size() > strs[i].size()) {
                        ans = ans.substr(0, strs[i].size());
                    }
                }
                return ans;
            }
        }
};

int main() {
}
