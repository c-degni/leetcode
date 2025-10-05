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
    ListNode* deleteMiddle(ListNode* head) {
        int s = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            s++;
            tmp = tmp->next;
        }

        if (s == 1) return nullptr;
        ListNode* parent = nullptr;
        tmp = head;
        for (int i = 0; i < s / 2; i++) {
            parent = tmp;
            tmp = tmp->next;
        }

        parent->next = tmp->next;
        delete tmp;
        return head;
    }
};
