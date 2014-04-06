#include "header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        vector <string> v;
        int i = a.size() - 1, j = b.size() - 1;
        int biu = 0;
        while(i >= 0 && j >= 0) {
            switch(a[i] - '0' + b[j] - '0' + biu) {
                case 0:
                    v.push_back("0");
                    biu = 0;
                    break;
                case 1:
                    v.push_back("1");
                    biu = 0;
                    break;
                case 2:
                    v.push_back("0");
                    biu = 1;
                    break;
                case 3:
                    v.push_back("1");
                    biu = 1;
                    break;
            }
            i--;
            j--;
        }
        while(i >= 0) {
            switch(a[i] - '0' + biu) {
                case 0:
                    v.push_back("0");
                    biu = 0;
                    break;
                case 1:
                    v.push_back("1");
                    biu = 0;
                    break;
                case 2:
                    v.push_back("0");
                    biu = 1;
                    break;
            }
            i--;
        }
        while(j >= 0) {
            switch(b[j] - '0' + biu) {
                case 0:
                    v.push_back("0");
                    biu = 0;
                    break;
                case 1:
                    v.push_back("1");
                    biu = 0;
                    break;
                case 2:
                    v.push_back("0");
                    biu = 1;
                    break;
            }
            j--;
        }
        if(biu) {
            v.push_back("1");
        }
        string ans = "";
        for(int k = v.size() - 1; k >= 0; k--) {
            ans += v[k];
        }
        return ans;
    }
};

int main() {
}
