#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int total = 0;
			ListNode * current = head;
			while( current != NULL) {
				total++;
				current = current -> next;
			}

			int dest = total - n + 1;
			int count = 0;
			ListNode * prev = NULL;
			current = head;
			while( current != NULL) {
				count ++;
				if( count == dest) {
					if( prev != NULL) {
						prev -> next = current -> next;
					}
					else {
						head = current -> next;
					}
					delete current;
					current = NULL;
					break;
				}
				else {
					prev = current;
					current = current -> next;
				}
			}
			return head;
		}
};

int main() {
	Solution a;
	ListNode * head = new ListNode( 1);
	head->next = new ListNode(2);
	ListNode * ans = a.removeNthFromEnd( head, 1);
}
