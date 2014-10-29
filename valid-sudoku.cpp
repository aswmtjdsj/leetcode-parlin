#include "header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++) {
            set <char> S;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    auto ret = S.insert(board[i][j]);
                    if(ret.second == false) {
                        return false;
                    }
                }
            }
        }
        
        for(int j = 0; j < 9; j++) {
            set <char> S;
            for(int i = 0; i < 9; i++) {
                if(board[i][j] != '.') {
                    auto ret = S.insert(board[i][j]);
                    if(ret.second == false) {
                        return false;
                    }
                }
            }
        }
        
        for(int k = 0; k < 9; k++) {
            int y = (k / 3) * 3, x = (k % 3) * 3;
            set <char> S;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(board[i+y][j+x] != '.') {
                        auto ret = S.insert(board[i+y][j+x]);
                        if(ret.second == false) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

int main() {
}
