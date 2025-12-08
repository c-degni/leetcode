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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* a = head;
        ListNode* b = a->next;
        ListNode* c = b->next;
        a->next = c;
        b->next = a;
        head = b;

        while (c && c->next) {
            ListNode* p = a;
            a = c;
            b = a->next;
            c = b->next;
            a->next = c;
            b->next = a;
            p->next = b;
        }

        return head;
    }
};
