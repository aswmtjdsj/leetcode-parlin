#include "header.h"

class Solution {
public:
    vector<string> ans;
    map<char,string> M;
    void dfs(string a, int d, string biu) {
        if(d == a.size()) {
            ans.push_back(biu);
            return ;
        }
        string temp = M[a[d]];
        for(int i = 0; i < temp.size();i++) {
            string s(1, temp[i]);
            biu += s;
            dfs(a, d+1, biu);
            biu = biu.substr(0, biu.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        M['2'] = "abc";
        M['3'] = "def";
        M['4'] = "ghi";
        M['5'] = "jkl";
        M['6'] = "mno";
        M['7'] = "pqrs";
        M['8'] = "tuv";
        M['9'] = "wxyz";
        ans.clear();
        string biu = "";
        dfs(digits, 0, biu);
        
        return ans;
    }
};

int main() {
}
