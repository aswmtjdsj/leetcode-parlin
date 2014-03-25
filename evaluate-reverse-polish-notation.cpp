#include "header.h"

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack <string> S;
        for(auto idx = tokens.begin(); idx != tokens.end(); idx++) {
            string cur = *idx;
            if((cur[0] >= '0' && cur[0] <= '9') || (cur[0] == '-' && cur.size() > 1)) {
                S.push(cur);
            }
            else {
                int a, b;
                string sa, sb;
                sb = S.top();
                S.pop();
                sa = S.top();
                S.pop();
                sscanf(sb.c_str(), "%d", &b);
                sscanf(sa.c_str(), "%d", &a);
                int temp;
                switch(cur[0]) {
                    case '+':
                        temp = a + b;
                        break;
                    case '-':
                        temp = a - b;
                        break;
                    case '*':
                        temp = a * b;
                        break;
                    case '/':
                        temp = a / b;
                        break;
                }
                string sc = to_string(temp);
                S.push(sc);
            }
        }
        string last = S.top();
        S.pop();
        int ans;
        sscanf(last.c_str(), "%d", &ans);
        return ans;
    }
};

int main() {
}
