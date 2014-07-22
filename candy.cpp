class Solution {
public:
    vector<int> dp;
    vector<int> c;
    int n;
    int dfs(int x) {
        if(dp[x] != -1) {
            return dp[x];
        }
        int l = -1, r = -1;
        if(x > 0) {
            if(c[x] > c[x-1]) {
                l = dfs(x-1) + 1;
            }
        }
        if(x < n - 1) {
            if(c[x] > c[x+1]) {
                r = dfs(x+1) + 1;
            }
        }
        int a = max(l, r);
        if(a == -1) {
            dp[x] = 1;
        }
        else {
            dp[x] = a;
        }
        return dp[x];
    }
    int candy(vector<int> &r) {
        c = r;
        dp.resize(r.size());
        fill(dp.begin(), dp.end(), -1);
        int ans = 0;
        n = r.size();
        for(int i = 0; i < n; i++) {
            if(dp[i] == -1) {
                dp[i] = dfs(i);
            }
            ans += dp[i];
        }
        return ans;
    }
};

