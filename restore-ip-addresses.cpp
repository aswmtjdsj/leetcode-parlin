#include "header.h"
class Solution {
public:
    vector <string> ans;
    void dfs(string a, vector<string> &t) {
        if(a.size()==0){
            if(t.size() < 4) {
                return ;
            }
            string biu = "";
            for(int i = 0; i < t.size(); i++) {
                biu += t[i];
                if(i != t.size() - 1) {
                    biu += ".";
                }
            }
            ans.push_back(biu);
        }
        else {
            if(a.size() != 0 && t.size() > 3) {
                return ;
            }
            for(int i = 0; i < min(3, (int)a.size()); i++) {
                string b = a.substr(0, i+1);
                int numb;
                istringstream(b) >> numb;
                if(to_string(numb) == b && numb >= 0 && numb <= 255) {
                    t.push_back(b);
                    dfs(a.substr(i+1, a.size()-(i+1)), t);
                    t.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if(s.size() == 0) {
            return ans;
        }
        vector<string> temp;
        dfs(s, temp);
        return ans;
    }
};

int main() {
}
