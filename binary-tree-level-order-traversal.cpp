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
        vector<vector<int> > levelOrder(TreeNode *root) {

            queue <TreeNode *> Q;
            Q.push(root);
            vector< vector<int> > ans;
            if(root == NULL) {
                return ans;
            }
            while(!Q.empty()) {
                int count = Q.size();
                vector<int> temp;
                while(!Q.empty()) {
                    TreeNode * cur = Q.front();
                    Q.pop();

                    temp.push_back(cur->val);
                    if(cur->left != NULL) {
                        Q.push(cur->left);
                    }
                    if(cur->right != NULL) {
                        Q.push(cur->right);
                    }
                    count--;
                    if(count == 0) {
                        ans.push_back(temp);
                        break;
                    }
                }
            }
            return ans;
        }
};

int main() {
}
