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
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        //case for one node
        if (!head->next)
            return NULL;
        ListNode *slow = head, *fast = head;
        //finding middle node
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //case where only two nodes are present
        if (!slow->next)
        {
            delete slow;
            head->next = NULL;
        }
        //here slow pointer is replaced with its next val and address of next next
        else
        {
            ListNode *temp = slow->next;
            *slow = *temp;
            delete temp;
        }
        return head;
    }
};