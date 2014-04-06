#include "header.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ans = 0, len = strlen(s);
        for(int i = len - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(ans != 0) {
                    break;
                }
                else {
                    ans = 0;
                }
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
}
