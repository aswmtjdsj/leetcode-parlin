#include "header.h"

class Solution {
    public:
        void solve(vector<vector<char>> &board) {
            int n = board.size(), m = 0;
            vector <vector<int>> status(n);
            if(n > 0) {
                m = board[0].size();
            }
            for(int i = 0; i < n; i++) {
                status[i].resize(m);
                for(int j = 0; j < m; j++) {
                    status[i][j] = board[i][j] == 'X'?0:1;
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(status[i][j] == 1) {
                        vector<pair<int,int>> temp;
                        queue<pair<int,int>> q;
                        q.push(make_pair(i, j));
                        status[i][j] = 2;
                        bool mark = true;
                        while(!q.empty()) {
                            pair<int,int> cur = q.front();
                            q.pop();
                            temp.push_back(cur);
                            int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
                            for(int k = 0; k < 4; k++) {
                                pair<int,int> next;
                                next.first = cur.first + dx[k];
                                next.second = cur.second + dy[k];
                                if(0 <= next.first && next.first < n && 0 <= next.second && next.second < m) {
                                    if(status[next.first][next.second] == 1) {
                                        q.push(next);
                                        status[next.first][next.second] = 2;
                                    }
                                }
                                else {
                                    mark = false;
                                }
                            }
                        }
                        if(!mark) {
                            for(int k = 0; k < static_cast<int>(temp.size()); k++) {
                                status[temp[k].first][temp[k].second] = 3;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(status[i][j] == 2) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};

int main() {
    Solution a;
    vector <char> b = {'O', 'O', 'O'};
    vector< vector<char> > bb;
    bb.push_back(b);
    bb.push_back(b);
    bb.push_back(b);
    a.solve(bb);
}
