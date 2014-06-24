/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL) {
            return;
        }
        queue<TreeLinkNode *> Q;
        Q.push(root);
        int current = 1, next = 0; // nodes in current layer and next layer
        while(!Q.empty()) {
            TreeLinkNode * cur = Q.front();
            Q.pop();
            current--;
            if(current != 0) {
                cur->next = Q.front();
            }
            else {
                cur->next = NULL;
            }
            if(cur->left != NULL) {
                Q.push(cur->left);
                next++;
            }
            if(cur->right != NULL) {
                Q.push(cur->right);
                next++;
            }
            if(current == 0) {
                current = next;
                next = 0;
            }
        }
    }
};
