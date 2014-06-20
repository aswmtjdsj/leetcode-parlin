#include "header.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parse;
        string ans;
        int i = 0, j = 0, n = path.size();
        while(i < n) {
            if(path[j] == '\/' || j == n) {
                if(i != j) {
                    string temp = path.substr(i+1,j-i-1);
                    if(temp.size() == 0) {
                    }
                    else if(temp == ".") {
                    }
                    else if(temp == "..") {
                        if(parse.size() > 0) {
                            parse.pop_back();
                        }
                    }
                    else {
                        parse.push_back(temp);
                    }
                    i=j;
                }
            }
            j++;
            if(j > n) {
                break;
            }
        }
        int num = parse.size();
        ans="\/";
        for(int i = 0; i < num; i++) {
            ans += parse[i];
            if(i != num - 1) {
                ans += "\/";
            }
        }
        return ans;
    }
};
