class Solution {
public:
    int tot;
    int ans;
    void dfs(vector <string> & store) {
        if(store.size() == tot) {
            ans++;
            return ;
        }
        int r = store.size(), c = tot;
        for(int i = 0; i < tot; i++) {
            bool mark = true;
            for(int x = 0; x < r; x++) { // vertical
                if(store[x][i] != '.') {
                    mark = false;
                    break;
                }
                if(i-(r-x) >= 0 && store[x][i-(r-x)] != '.') {
                    mark = false;
                    break;
                }
                if(i+(r-x) < tot && store[x][i+(r-x)] != '.') {
                    mark = false;
                    break;
                }
            }
            if(mark) {
                string biu(tot, '.');
                biu[i] = 'Q';
                store.push_back(biu);
                dfs(store);
                store.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        tot = n;
        ans = 0;
        vector <string> temp;
        dfs(temp);
        return ans;
    }
};
