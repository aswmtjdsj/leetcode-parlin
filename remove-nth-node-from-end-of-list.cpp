/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include "header.h"
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return head;
        ListNode * fast = head, * slow = head, * fast_p = NULL, * slow_p = NULL;
        n--;
        while(n--) {
            fast_p = fast;
            fast = fast->next;
            if(fast == NULL) { // if n is larger than the size of list
                return head;
            }
        }
        while(fast->next != NULL) { // in case of removing the last element
            fast_p = fast;
            fast = fast->next;
            slow_p = slow;
            slow = slow->next;
        }
        if(slow_p != NULL) {
            slow_p->next = slow->next;
        } else { // to remove the list head
            head = slow->next;
        }
        
        return head;
    }
};
