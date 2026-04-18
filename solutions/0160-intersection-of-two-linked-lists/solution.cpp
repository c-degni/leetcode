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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> sa;
        for (ListNode* tmp = headA; tmp != nullptr; tmp = tmp->next) {
            sa.insert(tmp);
        }
        for (ListNode* tmp = headB; tmp != nullptr; tmp = tmp->next) {
            if (sa.contains(tmp)) return tmp;
        }
        return nullptr;
    }
};
