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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * cur = head, * prev = NULL;
        while(cur != NULL) {
            if(prev != NULL && prev->val == cur->val) {
                prev->next = cur->next;
                cur = prev;
            }
            prev = cur;
            cur = cur->next;
            
        }
        return head;
    }
};

int main() {
}
