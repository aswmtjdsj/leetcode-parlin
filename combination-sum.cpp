#include "header.h"

class Solution {
    public:
        void dfs(int cur, vector <int> &C, set < vector <int> > & s, vector <int> & temp) {
            if(cur == 0) {
                vector <int> gogogo = temp;
                sort(gogogo.begin(), gogogo.end());
                if(s.find(temp) == s.end()) {
                    s.insert(gogogo);
                    return ;
                }
            }
            for(auto i: C) {
                if(cur - i >= 0) {
                    temp.push_back(i);
                    dfs(cur-i, C, s, temp);
                    temp.pop_back();
                }
            }
        }
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            sort(candidates.begin(), candidates.end());
            set < vector<int> > s;
            vector < vector<int> > ans;
            vector <int> temp;
            dfs(target, candidates, s, temp);
            for(auto i: s) {
                ans.push_back(i);
            }
            return ans;
        }
};

int main() {
    Solution a;
    auto b = vector<int> ({2, 3});
    auto biu = a.combinationSum(b, 100);
    for(auto i: biu) {
        for(auto j: i) {
            cout << j << ' ';
        } cout << endl;
    }
}