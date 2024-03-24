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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

	    return recurRemove(head, n, n);
        
    }

    ListNode* recurRemove(ListNode* head, int n, int& counter)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode* NextNode = recurRemove(head->next, n, counter);
        if (!NextNode || counter < n)
        {
            counter--;
        }

        if (counter == 0)
        {
            //delete head;
            return NextNode;
        }

        head->next = NextNode;
        return head;
    }
};