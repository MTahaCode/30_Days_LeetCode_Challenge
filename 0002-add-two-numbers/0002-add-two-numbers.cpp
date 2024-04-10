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
        return helperAdd(l1, l2, 0);
    }

    ListNode* helperAdd(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2)  {
            if (!carry) return nullptr;
            else return new ListNode(carry);
        }

        int currVal = carry + ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);
        ListNode* currNode = new ListNode(currVal % 10);

        if (!l2) { //there is only l1
            currNode->next = helperAdd(l1->next, l2, currVal / 10);
        }
        else if (!l1) { //there is only l2
            currNode->next = helperAdd(l1, l2->next, currVal / 10);
        }
        else {
            currNode->next = helperAdd(l1->next, l2->next, currVal / 10);
        }
        return currNode;
    }
};