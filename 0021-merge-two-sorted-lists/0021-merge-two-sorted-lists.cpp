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
        
        if (!list1)
        {
            return list2;
        }
        
        ListNode* currL1 = list1;
        ListNode* prevL1 = nullptr;

        while (list2)
        {
            if (!currL1)
            {
                prevL1->next = list2;// for the end of the list1
                break;
            }
            else if (list2->val < currL1->val)
            {
                //removing from second list
                ListNode* replacerNode = list2;
                list2 = list2->next;

                if (prevL1) // for somewhere in between the list1
                {
                    prevL1->next = replacerNode;
                }
                else // for the start of list1
                {
                    list1 = replacerNode;
                }

                replacerNode->next = currL1;
                prevL1 = replacerNode;
                continue;
            }
            prevL1 = currL1;
            currL1 = currL1->next;
        }
        return list1;
    }
};

