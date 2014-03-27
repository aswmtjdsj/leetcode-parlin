#include "header.h"

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            if(gas.size() == 0) {
                return 0;
            }
            int i = 0, j = 1;
            int remain = 0;
            int n = gas.size();
            do {
                cout << i << ' ' << j << endl;
                cout << remain << ' ' << gas[(j-1+n)%n] << ' ' <<  cost[(j-1+n)%n] << endl;
                if(remain + gas[(j-1+n)%n] >= cost[(j-1+n)%n]) { 
                    // can reach j
                    // hard to select status equation
                    cout << "aaa" << endl;
                    remain += gas[(j-1+n)%n] - cost[(j-1+n)%n];
                    j++;
                }
                else {
                    cout << "biu" << endl;
                    if((i + 1) % n == j % n) { // confusing about updating indices
                        j++;
                    }
                    else {
                        remain -= gas[i % n];
                        remain += cost[i % n];
                    }
                    i++;
                }
                if(j == i + n + 1) {
                    return i%n;
                }
            } while(i != n); // difficult to set terminal condition
            return -1;
        }
};

int main() {
    vector<int> g, c;
    g.push_back(1);
    g.push_back(2);
    c.push_back(2);
    c.push_back(1);
    Solution a;
    cout << a.canCompleteCircuit(g, c) << endl;
}
