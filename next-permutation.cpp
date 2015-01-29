class Solution {
public:
    void nextPermutation(vector<int> &v) {
        int to_change = -1, be_changed = -1;
        for(int idx = v.size() - 1; idx >= 0; idx--) {
            for(int jdx = idx - 1; jdx >= 0; jdx--) {
                if(v[idx] > v[jdx]) { // can be changed
                    if(to_change == -1) {
                        to_change = jdx;
                        be_changed = idx;
                    } else {
                        if(to_change < jdx) { // choose the least significant digit to change
                            to_change = jdx;
                            be_changed = idx;
                        } else if(to_change == jdx && v[idx] < v[be_changed]) { // the smaller the better
                            be_changed = idx;
                        }
                    }
                }
            }
        }
        if(to_change != -1) {
            swap(v[to_change], v[be_changed]); 
            sort(v.begin() + to_change + 1, v.end()); // sort the remaining
        } else {
            sort(v.begin(), v.end());
        }
        return;
    }
};
