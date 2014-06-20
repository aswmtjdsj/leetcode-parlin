
class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            int step = 0;
            ListNode * ans = NULL, * cur;
            while(l1 != NULL && l2 != NULL) {
                int temp = l1->val + l2->val + step;
                step = temp > 9?1:0;
                temp %= 10;
                if(ans == NULL) {
                    cur = new ListNode(temp);
                    ans = cur;
                }
                else {
                    cur->next = new ListNode(temp);
                    cur = cur->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            while(l1 != NULL) {
                int temp = l1->val + step;
                step = temp > 9?1:0;
                temp %= 10;
                if(ans == NULL) {
                    cur = new ListNode(temp);
                    ans = cur;
                }
                else {
                    cur->next = new ListNode(temp);
                    cur = cur->next;
                }
                l1 = l1->next;
            }
            while(l2 != NULL) {
                int temp = l2->val + step;
                step = temp > 9?1:0;
                temp %= 10;
                if(ans == NULL) {
                    cur = new ListNode(temp);
                    ans = cur;
                }
                else {
                    cur->next = new ListNode(temp);
                    cur = cur->next;
                }
                l2 = l2->next;
            }
            if(step != 0) {
                int temp = step;
                step = temp > 9?1:0;
                temp %= 10;
                if(ans == NULL) {
                    cur = new ListNode(temp);
                    ans = cur;
                }
                else {
                    cur->next = new ListNode(temp);
                    cur = cur->next;
                }
            }
            return ans;
        }
};
