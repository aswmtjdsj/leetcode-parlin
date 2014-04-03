#include "header.h"

class Solution {
    public:
        bool isPalindrome(string s) {
            int len = s.size();
            vector<char> v;
            for(int i = 0; i < len; i++) {
                if(isdigit(s[i])) {
                    v.push_back(s[i]);
                }
                else if(isalpha(s[i])) {
                    if(isupper(s[i])) {
                        v.push_back(s[i] - 'A' + 'a');
                    }
                    else {
                        v.push_back(s[i]);
                    }
                }
            }
            int l = v.size();
            int a = 0, b = l - 1;
            while(a < b) {
                if(v[a] != v[b]) {
                    return false;
                }
                a++;
                b--;
            }
            return true;
        }
};

int main() {
}
