#include <vector>
#include <iostream>
#include <string>
#include "tree_node.h"
using namespace std;

class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            int n = num.size();
            if(n == 0) {
                return NULL;
            }
            int mid = n / 2;
            TreeNode * root = new TreeNode(num[mid]);
            if( mid > 0) {
                vector <int> left(num.begin(), num.begin() + mid);
                root->left = sortedArrayToBST(left);
            }
            if( mid < n - 1) {
                vector <int> right(num.begin() + mid + 1, num.end());
                root->right = sortedArrayToBST(right);
            }
            return root;
        }
        void traverse(TreeNode * cur, string &parser) {
            if(cur != NULL) {
                printf("%s%d\n", parser.c_str(), cur->val);
                string p = parser + "-";
                traverse(cur->left, p);
                traverse(cur->right, p);
            }
        }
};

int main() {
    Solution a;
    int _b[6] = {0, 1, 2, 3, 4, 5};
    vector<int> b(_b, _b+6);
    TreeNode * bla = a.sortedArrayToBST(b);

    string i = "";
    a.traverse(bla, i);
}
