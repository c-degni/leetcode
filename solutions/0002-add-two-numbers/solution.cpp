/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tmp = nullptr;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int c = 0;
        while (t1 && t2) {
            int s = t1->val + t2->val + c;
            if (s > 9) {
                c = 1;
                s %= 10;
            } else {
                c = 0;
            }

            if (!head) {
                head = new ListNode(s);
                tmp = head;
            } else {
                tmp->next = new ListNode(s);
                tmp = tmp->next;
            }

            t1 = t1->next;
            t2 = t2->next;
        }

        while (t1) {
            int s = t1->val + c;
            if (s > 9) {
                c = 1;
                s %= 10;
            } else {
                c = 0;
            }
            tmp->next = new ListNode(s);
            tmp = tmp->next;
            t1 = t1->next;
        }

        while (t2) {
            int s = t2->val + c;
            if (s > 9) {
                c = 1;
                s %= 10;
            } else {
                c = 0;
            }
            tmp->next = new ListNode(s);
            tmp = tmp->next;
            t2 = t2->next;
        }

        if (c) tmp->next = new ListNode(c);

        return head;
    }
};
