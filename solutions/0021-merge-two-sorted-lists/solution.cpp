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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while (t1 && t2) {
            if (t1->val < t2->val) {
                if (!head) {
                    head = t1; 
                    tail = head;
                } else {
                    tail->next = t1; 
                    tail = tail->next;
                }
                t1 = t1->next;
            } else {
                if (!head) {
                    head = t2; 
                    tail = head;
                } else {
                    tail->next = t2; 
                    tail = tail->next;
                }
                t2 = t2->next;
            }
        }

        while (t1) {
            if (!head) {
                head = t1; 
                tail = head;
            } else {
                tail->next = t1; 
                tail = tail->next;
            }
            t1 = t1->next;
        }

        while (t2) {
            if (!head) {
                head = t2; 
                tail = head;
            } else {
                tail->next = t2; 
                tail = tail->next;
            }
            t2 = t2->next;
        }

        return head;
    }
};
