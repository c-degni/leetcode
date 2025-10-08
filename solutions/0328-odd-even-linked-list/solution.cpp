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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* optr = head;
        ListNode* ehead = head->next;
        ListNode* eptr = ehead;
        while (eptr != nullptr && eptr->next != nullptr) {
            optr->next = optr->next->next;
            eptr->next = eptr->next->next;
            optr = optr->next;
            eptr = eptr->next;
        }
        optr->next = ehead;
        return head;
    }
};
