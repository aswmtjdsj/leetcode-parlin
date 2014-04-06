#include "header.h"

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector < vector<int> > ans;
        int n = S.size();
        sort(S.begin(), S.end());
        for(int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                if(((1 << j) & i) > 0) { // non-descending!!!! according to S's order
                    temp.push_back(S[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
}
