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
    ListNode* mergeLists(ListNode* l1, ListNode* l2)
    {
        ListNode* mergedList = nullptr;
        ListNode* endNode = nullptr;
        while (l1 || l2)
        {
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    if (!mergedList)
                    {
                        mergedList = l1;
                        endNode = l1;
                        l1 = l1->next;
                        endNode->next = nullptr;
                    }
                    else
                    {
                        endNode->next = l1;
                        l1 = l1->next;
                        endNode = endNode->next;
                        endNode->next = nullptr;
                    }
                }
                else
                {
                    if (!mergedList)
                    {
                        mergedList = l2;
                        endNode = l2;
                        l2 = l2->next;
                        endNode->next = nullptr;
                    }
                    else
                    {
                        endNode->next = l2;
                        l2 = l2->next;
                        endNode = endNode->next;
                        endNode->next = nullptr;
                    }
                }
            }
            else if (l1)
            {
                if (!mergedList)
                {
                    mergedList = l1;
                    endNode = l1;
                    l1 = l1->next;
                    endNode->next = nullptr;
                }
                else
                {
                    endNode->next = l1;
                    l1 = l1->next;
                    endNode = endNode->next;
                    endNode->next = nullptr;
                }
            }
            else
            {
                if (!mergedList)
                {
                    mergedList = l2;
                    endNode = l2;
                    l2 = l2->next;
                    endNode->next = nullptr;
                }
                else
                {
                    endNode->next = l2;
                    l2 = l2->next;
                    endNode = endNode->next;
                    endNode->next = nullptr;
                }
            }
        }
        return mergedList;
    }

    ListNode* sortList(ListNode* head) {

        if (!head || !head->next)
        {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = nullptr;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            
            slow = (!slow) ? head: slow->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        
        return mergeLists(sortList(l1), sortList(l2));
    }
};