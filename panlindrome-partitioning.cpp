#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<string> > ans;
        vector< vector<bool> > dp;
        string p;
        int len;
        void dfs(vector<int> & ids) {
            if(*(ids.rbegin()) == len) {
                vector<string> tt;
                for(int id = 0; id < ids.size() - 1; id++) {
                    tt.push_back(p.substr(ids[id], ids[id+1] - ids[id]));
                }
                ans.push_back(tt);
                return ;
            }
            else {
                int cur = *(ids.rbegin());
                for(int i = cur+1; i <= len; i++) {
                    if(dp[cur][i]) {
                        ids.push_back(i);
                        dfs(ids);
                        ids.pop_back();
                    }
                }
            }
        }

        vector<vector<string> > partition(string s) {
            ans.clear();
            len = s.size();
            if(len==0) {
                vector <vector<string> > a(0);
                return a;
            }
            p = s;
            dp.resize(len+1);
            for(int i = 0; i <= len; i++) {
                dp[i].resize(len+1);
                for(int j = 0; j <= len; j++) {
                    dp[i][j] = false;
                }
            }
            for(int i = 0; i < len; i++) {
                dp[i][i] = true;
                dp[i][i+1] = true;
            }
            for(int j = 2; j <= len; j++) {
                for(int i = 0; i < len; i++) {
                    int k = i + j - 1;
                    if(k >= len) {
                        break;
                    }
                    if(s[i] == s[k] && dp[i+1][k]) {
                       dp[i][k+1] = true; 
                    }
                }
            }
            for(int i = 0; i < len; i++) {
                for(int j = 0; j <= len; j++) {
                    printf("%d%c", (int)dp[i][j], j==len?'\n':' ');
                }
            }

            vector <int> temp;
            temp.push_back(0);
            dfs(temp);

            return ans;
        }
};

int main() {
    Solution a;
    string s = "aabbaa";
    cout << s << endl;
    vector <vector<string> > p = a.partition(s);
    for(auto idx = p.begin(); idx != p.end(); idx++) {
        for(auto idp = idx->begin(); idp != idx->end(); idp++) {
            cout << *idp << ' ';
        }
        cout << '\n';
    }
}
