class Solution {
public:
    string minWindow(string S, string T) { // contain "ALL" char in T!!!
        int i = 0, j = 0, n = S.size(), m = T.size(), p = 0, ans = n;
        string ret;
        int pat[200] = {0};
        for(int k = 0; k < m; k++) {
            if(pat[T[k]] == 0) { // count the kind of character, not frequency
                p++;
            }
            pat[T[k]]++;
        }
        int biu[200] = {0};
        int cnt = 0;
        while(j < n) {
            biu[S[j]]++;
            if(biu[S[j]] == pat[S[j]]) {
                cnt++;
            }
            while(cnt == p) {
                if(ans >= j - i + 1) {
                    ans = j - i + 1;
                    ret = S.substr(i, j-i+1);
                }
                biu[S[i]]--;
                if(pat[S[i]] > biu[S[i]]) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ret;
    }
};
