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
    void reorderList(ListNode* head) {
        
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while (slowPtr->next && slowPtr->next->next)
        {
            while (fastPtr->next->next)//go to second last node
            {
                fastPtr = fastPtr->next;
            }

            fastPtr->next->next = slowPtr->next;
            slowPtr->next = fastPtr->next;
            fastPtr->next = nullptr;

            slowPtr = slowPtr->next->next;
            fastPtr = slowPtr;
        }
        
    }
};