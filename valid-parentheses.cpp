#include "header.h"

class Solution {
    public:
        bool isValid(string s) {
            stack <char> S;
            int len = s.size();
            for(int i = 0; i < len; i++) {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    S.push(s[i]);
                }
                else {
                    if(S.empty() == true) {
                        return false;
                    }
                    char prev = S.top();
                    S.pop();
                    if((prev == '(' && s[i] != ')') 
                            || (prev == '[' && s[i] != ']') 
                            || (prev == '{' && s[i] != '}') 
                      ) {
                        return false;
                    }
                }
            }
            if(S.empty() == true)
                return true;
            else
                return false;
        }
};

int main() {
}
