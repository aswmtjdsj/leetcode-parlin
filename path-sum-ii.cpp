#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<vector<int> > ans;
        int obj;
        void dfs(TreeNode *cur, vector<int> &q) {
            bool mark = false;
            if(cur->left) {
                q.push_back(cur->left->val);
                dfs(cur->left, q);
                q.pop_back();
                mark = true;
            }
            if(cur->right) {
                q.push_back(cur->right->val);
                dfs(cur->right, q);
                q.pop_back();
                mark = true;
            }

            if(!mark) {
                int s = 0;
                for(int i = 0; i < q.size(); i++) {
                    s += q[i];
                }
                if(s == obj) {
                    ans.push_back(q);
                }
            }
        }
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector <int> que;
            obj = sum;
            ans.clear();
            if(root == NULL) {
                return ans;
            }
            que.push_back(root->val);
            dfs(root, que);
            return ans;
        }
};

int main() {
    Solution a;
    TreeNode * root = new TreeNode(0);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(1);
    vector< vector<int> > ans = a.pathSum(root, 1);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
