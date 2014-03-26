#include "header.h"

class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            map<string, int> dis;
            queue<string> Q;
            Q.push(start);
            dis[start] = 1;
            dict.insert(end);
            while(!Q.empty()) {
                string cur = Q.front();
                Q.pop();
                for(int i = 0; i < cur.size(); i++) {
                    for(int c = 'a'; c <= 'z'; c++) {
                        string temp = cur;
                        if(temp[i] != c) {
                            temp[i] = c;
                            if(dict.find(temp) != dict.end()) {
                                dict.erase(temp);
                                Q.push(temp);
                                dis[temp] = dis[cur] + 1;
                            }
                        }
                    }
                }
            }
            return dis[end];
        }
};

int main() {
    Solution a;
    unordered_set<string> b;
    string p, q, temp;
    freopen("word-ladder.out", "r", stdin);
    cin >> p;
    cin >> q;
    while(cin >> temp) {
        b.insert(temp);
    }
    cout << a.ladderLength(p, q, b) << endl;
    fclose(stdin);
}
