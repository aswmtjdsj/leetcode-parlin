#include "header.h"

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            map <int, set<pair<pair<int,int>, pair<int,int> > > > M;
            int n = num.size();
            for(int i = 0; i < n; i ++) {
                for(int j = i + 1; j < n; j++) {
                    int s = num[i] + num[j];
                    M[s].insert(make_pair(make_pair(i, num[i]), make_pair(j, num[j])));
                }
            }
            vector< vector<int> > ans;
            vector< vector<pair<int,int> > > temp_ans;

            for(int i = 0; i < n; i++) {
                if(M.find(-num[i]) != M.end()) {
                    auto S = M[-num[i]];
                    for(auto idx = S.begin(); idx != S.end(); idx++) {
                        auto a = idx->first;
                        auto b = idx->second;
                        if(a.first != i && b.first != i) {
                             // cout << "(" << a.first << "," << a.second << ") (" << b.first << ", " << b.second << ") (" << i << ", " << num[i] << ")" << endl;
                            vector<pair<int,int> > temp;
                            temp.push_back(a);
                            temp.push_back(b);
                            temp.push_back(make_pair(i, num[i]));
                            sort(temp.begin(), temp.end());
                            temp_ans.push_back(temp);
                        }
                    }
                }
            }
            sort(temp_ans.begin(), temp_ans.end());
            temp_ans.resize(distance(temp_ans.begin(), unique(temp_ans.begin(), temp_ans.end())));
            for(auto i = temp_ans.begin(); i != temp_ans.end(); i++) {
                vector <int> t;
                for(auto idx = i->begin(); idx != i->end(); idx++) {
                    cout << idx->first << ' ' << idx->second << ' ';
                    t.push_back(idx->second);
                }
                cout << endl;
                ans.push_back(t);
            }
            return ans;
        }
};

int main() {
    Solution a;
    int kius[] = {-1,0,1,2,-1,-4};
    // int kius[] = {-13,10,11,-3,8,11,-4,8,12,-13,5,-6,-4,-2,12,11,7,-7,-3,10,12,13,-3,-2,6,-1,14,7,-13,8,14,-10,-4,10,-6,11,-2,-3,4,-13,0,-14,-3,3,-9,-6,-9,13,-6,3,1,-9,-6,13,-4,-15,-11,-12,7,-9,3,-2,-12,6,-15,-10,2,-2,-6,13,1,9,14,5,-11,-10,14,-5,11,-6,6,-3,-8,-15,-13,-4,7,13,-1,-9,11,-13,-4,-15,9,-4,12,-4,1,-9,-5,9,8,-14,-1,4,14};
    vector <int> kiu(kius, kius+sizeof(kius)/sizeof(int));
    vector<vector<int> > biu = a.threeSum(kiu);
    for(auto idx = biu.begin(); idx != biu.end(); idx++) {
        auto arr = *idx;
        for(auto i = arr.begin(); i != arr.end(); i++) {
            cout << *i << ' ';
        }
        cout << endl;
    }
}
