#include "header.h"

class Solution {
public:
    vector< vector<int> > ans;
    void dfs(int n, int step, int k, vector<int> temp) {
        if(step == k) {
            ans.push_back(temp);
            return ;
        }
        int last;
        if(temp.size() == 0) last = 0;
        else last = *(temp.rbegin());
        if(last == n) {
            return ;
        }
        for(int i = last + 1; i <= n; i++) {
            temp.push_back(i);
            dfs(n, step + 1, k, temp);
            temp.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        vector<int> temp;
        dfs(n, 0, k, temp);
        return ans;
    }
};

int main() {
}
