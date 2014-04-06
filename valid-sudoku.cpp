#include "header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int n = board.size();
        //horizontal
        for(int i = 0; i < n; i++) {
            int vis[10] = {0};
            for(int j = 0; j < n; j++) {
                if(isdigit(board[i][j])) {
                    vis[board[i][j]-'0']++;
                    if(vis[board[i][j]-'0'] > 1) {
                        return false;
                    }
                }
            }
        }
        //vertical
        for(int i = 0; i < n; i++) {
            int vis[10] = {0};
            for(int j = 0; j < n; j++) {
                if(isdigit(board[j][i])) {
                    vis[board[j][i]-'0']++;
                    if(vis[board[j][i]-'0'] > 1) {
                        return false;
                    }
                }
            }
        }
        //inner 9
        for(int i = 0; i < n; i++) {
            int vis[10] = {0};
            for(int j = 0; j < n; j++) {
                int row = i / 3, col = i % 3;
                int subrow = j / 3, subcol = j % 3;
                int ai = row * 3 + subrow, aj = col * 3 + subcol;
                if(isdigit(board[ai][aj])) {
                    vis[board[ai][aj] - '0']++;
                    if(vis[board[ai][aj] - '0'] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
}
