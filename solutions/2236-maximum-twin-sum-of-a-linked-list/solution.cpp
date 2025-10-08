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
    int pairSum(ListNode* head) {
        ListNode* curr = head;
        int n = 0;
        while (curr) {
            n++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < n / 2; i++) {
            curr = curr->next;
        }

        ListNode* head2 = nullptr; // Treat this as res
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            if (!tmp) head2 = curr;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        prev = head;
        int m = 0;
        while (head2) {
            m = std::max(prev->val + head2->val, m);
            prev = prev->next;
            head2 = head2->next;
        }
        return m;
    }
};
