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
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        
        while(fastPtr && fastPtr->next!=NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        return slowPtr;
    }
};