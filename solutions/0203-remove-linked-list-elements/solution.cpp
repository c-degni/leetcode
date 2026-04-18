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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        ListNode* tmp = head;
        ListNode* prev = head;
        while (tmp) {
            if (tmp->val == val) {
                if (tmp == head) {
                    tmp = tmp->next;
                    delete prev;
                    prev = tmp;
                    head = tmp;
                } else {
                    prev->next = tmp->next;
                    delete tmp;
                    tmp = prev->next;
                }
            } else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
