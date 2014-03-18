#include "header.h"
#include "tree_node.h"

/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        int ans;
        void dfs(TreeNode *cur, vector<int> &digits) {
            bool mark = false;
            digits.push_back(cur->val);
            if(cur -> left != NULL) {
                dfs(cur->left, digits);
                mark = true;
            }
            if(cur -> right != NULL) {
                dfs(cur->right, digits);
                mark = true;
            }
            if(!mark) {
                int temp = 0;
                for(int i = 0; i < digits.size(); i++) {
                    temp *= 10;
                    temp = temp + digits[i];
                }
                ans += temp;
            }
            digits.pop_back();
        }
        int sumNumbers(TreeNode *root) {

            ans = 0;
            if(root != NULL) {
                vector<int> digits;
                dfs(root, digits);
            }
            return ans;
        }
};

int main() {
}
