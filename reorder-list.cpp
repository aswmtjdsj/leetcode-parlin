#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void reorderList(ListNode *head) {
            ListNode * cur, * past, *next;
            cur = head;
            int cnt = 0;
            while(cur != NULL) {
                cnt++;
                if(cur->next != NULL) {
                    past = cur;
                    cur = cur->next;
                }
                else
                    break;
            }
            if(cnt < 3)
                return ;
            next = head->next;
            head->next = cur;
            past->next = NULL;
            cur->next = next;
        }
};

int main() {
    Solution a;
    ListNode * bla = new ListNode(1);
    bla->next = new ListNode(2);
    bla->next->next = new ListNode(3);
    bla->next->next->next = NULL;
    a.reorderList(bla);
    for(ListNode * head = bla; head != NULL; head = head->next) {
        cout << head->val << endl;
    }
}
