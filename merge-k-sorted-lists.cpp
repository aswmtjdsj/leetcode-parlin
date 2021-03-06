#include "header.h"

/*class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * head = NULL, * biu = NULL;
        int s = lists.size();
        while(true) {
            int MIN = INT_MAX;
            int f = -1;
            for(int i = 0; i < s; i++) {
                ListNode * temp = lists[i];
                if(temp != NULL && temp->val < MIN) {
                    MIN = temp->val;
                    f = i;
                }
            }
            //cout << lists[f]->val << endl;
            if(f == -1) {
                break;
            }
            else {
                if(head == NULL) {
                    head = new ListNode(lists[f]->val);
                }
                else {
                    if(head->next == NULL) {
                        head->next = new ListNode(lists[f]->val);
                        biu = head->next;
                    }
                    else {
                        biu->next = new ListNode(lists[f]->val);
                        biu = biu->next;
                    }
                }
                lists[f] = lists[f]->next;
           }
        }
        return head;
    }
};*/

//  its first element is always the greatest of the elements it contains
struct Order { // comparitor
    bool operator () (ListNode * const & a, ListNode * const & b) { return a->val > b->val; }
};

class Solution {
    public:

        ListNode *mergeKLists(vector<ListNode *> &lists) {
            priority_queue <ListNode *, vector <ListNode *>, Order> q;
            ListNode * ret = NULL, * cur = ret;
            for(auto idx: lists) {
                if(idx != NULL) {
                    q.push(idx);
                }
            }
            while(!q.empty()) {
                ListNode * min = q.top();
                q.pop();
                if(cur == NULL) {
                    ret = new ListNode(min->val);
                    cur = ret;
                } else {
                    cur->next = new ListNode(min->val);
                    cur = cur->next;
                }
                min = min->next;
                if(min != NULL) {
                    q.push(min);
                }
            }
            return ret;
        }
};

int main() {
    Solution a;
    vector<ListNode *> lists;
    ListNode * biu = new ListNode(0), * qiu = biu;
    qiu->next = new ListNode(2);
    qiu->next->next = new ListNode(5);
    lists.push_back(biu);
    ListNode * ans = a.mergeKLists(lists);
    while(ans != NULL) {
        cout << ans->val << endl;
        ans = ans->next;
    }
}
