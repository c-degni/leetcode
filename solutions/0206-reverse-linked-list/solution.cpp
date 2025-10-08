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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* res = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            if (!tmp) res = curr;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return res;
    }
};
