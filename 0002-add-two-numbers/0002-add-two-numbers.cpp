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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* SumHead = nullptr;

        ListNode* curr = nullptr;
        while (l1 || l2) {
            int currVal = carry + ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);

            ListNode* it_curr = new ListNode(currVal % 10);
            carry = currVal / 10;

            if (!SumHead) {
                SumHead = it_curr;
                curr = it_curr;
            }
            else {
                curr->next = it_curr;
                curr = curr->next;
            }

            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }
        
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return SumHead;
    }
};