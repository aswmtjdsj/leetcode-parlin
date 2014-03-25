#include "list_node.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * cur = head;
        bool mark = false;
        while(cur != NULL) {
            if(cur->val == -28) {
                mark = true;
                break;
            }
            cur->val = -28;
            cur = cur->next;
        }
        return mark;
    }
};

int main() {
}
