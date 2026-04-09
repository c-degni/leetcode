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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) return head;
        int n = 0;
        for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) n++;
        if (n == 0 || n == 1) return head;
        k %= n;
        if (k == 0) return head;


        ListNode* tmp = head;
        for (int i = 1; i < n - k; i++) {
            tmp = tmp->next;
        }

        ListNode* h1 = tmp->next;
        tmp->next = nullptr;
        tmp = h1;
        while (tmp->next) tmp = tmp->next;
        tmp->next = head;
        return h1;
    }
};
