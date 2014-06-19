#include "header.h"

class Solution {
    public:
        int atoi(const char *str) {
            int flag = 0; // face nothing
            const char * p = str;
            long long ans = 0;
            while(*p != '\0') {
                if(*p == '-') {
                    if(flag == 0) {
                        flag = -1;
                    }
                    else {
                        break;
                    }
                }
                else if(*p == '+') {
                    if(flag == 0) {
                        flag = 1;
                    }
                    else {
                        break;
                    }
                }
                else if(isdigit(*p)) {
                    if(flag == 0) {
                        flag = 1;
                    }
                    ans *= 10ll;
                    ans += (*p) - '0';
                    if(flag != -1 && ans >= INT_MAX) {
                        return INT_MAX;
                    }
                    else if(flag == -1 && -ans <= INT_MIN) {
                        return INT_MIN;
                    }
                }
                else if(*p == ' '){
                    if(flag == 0) {
                    }
                    else {
                        break;
                    }
                }
                else{
                    break;
                }
                p++;
            }
            if(flag == 1 or flag == 0) {
            }
            else if(flag == -1) {
                ans = -ans;
            }
            return ans;
        }
};

int main() {
    Solution a;
    cout << a.atoi("") << endl;
}
