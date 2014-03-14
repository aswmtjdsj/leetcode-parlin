#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            int len = s.size();
            //bool * dp = new bool[len+1]; // it's fucking WA on leetcode, why?
            bool dp[10000];
            memset(dp, 0, sizeof(dp));
            dp[0] = true; // dp[i] means str of which the last index is i-1 exists or not
            for(int i = 1; i <= len; i++) {
                for(int j = 0; j < i; j++) {
                    if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[len];
        }
};

int main() {
    Solution a;

    unordered_set <string> b;
    b.insert("aaaa");
    b.insert("aa");
    cout << a.wordBreak("aaaaaaa", b) << endl;
}
