#include "header.h"

class Solution {
    public:
        int sqrt(int x) {
            long long count = x + 1ll - 0ll, step, cur, base = 0;
            while(count > 0) {
                cur = base;
                step = count / 2;
                cur += step;
                show(count);
                show(step);
                show(cur);
                show(base);
                if(cur * cur < x) {
                    base = ++cur;
                    count -= step + 1;
                }
                else {
                    count = step;
                }
            }
            long long ans = base;
            if(ans * ans > x) ans--;
            return ans;
        }
};

int main() {
    Solution a;
    int p;
    while(cin >> p) {
        cout << a.sqrt(p) << endl;
    }
}
