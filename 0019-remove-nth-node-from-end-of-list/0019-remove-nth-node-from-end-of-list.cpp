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
        
        
        ListNode* aheadNode = head;

        ListNode* prevOfLagging = nullptr;
        ListNode* laggingNode = head;

        for (int i = 0; i < n; i++)
        {
            aheadNode = aheadNode->next;
        }

        while (aheadNode)
        {
            aheadNode = aheadNode->next;

            prevOfLagging = laggingNode;
            laggingNode = laggingNode->next;
        }

        ListNode* temp = laggingNode->next;
        delete laggingNode;
        
        
        if (prevOfLagging)
        {
            
            prevOfLagging->next = temp;
        }
        else
        {
            head = temp;
        }

        return head;
    }
};