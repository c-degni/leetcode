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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = 0;
        ListNode* tmp;
        for (tmp = head; tmp != nullptr; tmp = tmp->next) s++;

        if (n == s) {
            tmp = head;
            head = head->next;
            delete tmp;
        } else {
            tmp = head;
            for (int i = 0; i < s - n - 1; i++)  tmp = tmp->next;
            ListNode* tmp2 = tmp->next;
            tmp->next = tmp->next->next;
            delete tmp2;
        }

        return head;
    }
};
