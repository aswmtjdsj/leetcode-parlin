class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int id = 0, i = 0, j = 0, cnt = 0, n = matrix.size(), m = (n > 0)?matrix[0].size(): 0;
        vector <int> ans;
        ans.resize(m*n);
        int sing = 0;
        if(n == 0) goto term;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sing -= matrix[i][j];
            }
        }
        while(true) {
            ans[cnt++] = matrix[j][i];
            matrix[j][i] = sing;
            int ni, nj, nid;
            bool flag = false;
            for(nid = 0; nid < 4; nid++) {
                ni = i + dx[(id+nid)%4];
                nj = j + dy[(id+nid)%4];
                if(0 <= ni && ni < m && 0 <= nj && nj < n && matrix[nj][ni] != sing) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                id = (id + nid)%4;
                i = ni;
                j = nj;
            } else {
                break;
            }
        }
term:
        return ans;
    }
};
