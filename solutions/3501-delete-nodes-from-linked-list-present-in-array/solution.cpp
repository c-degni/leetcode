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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode* tmp = head;
        ListNode* p = nullptr;

        while (tmp) {
            if (s.count(tmp->val)) {
                if (tmp == head) {
                    head = tmp->next;
                    // delete tmp;
                    tmp = head;
                } else {
                    p->next = tmp->next;
                    // delete tmp;
                    tmp = p->next;
                }
            } else {
                p = tmp;
                tmp = p->next;
            }
        }
        return head;
    }
};
