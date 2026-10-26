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
ListNode* reverse(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return head;
ListNode* newHead=reverse(head->next);
ListNode* front=head->next;
front->next=head;
head->next=NULL;
return newHead;
}
    int pairSum(ListNode* head) {
        if(head==NULL)return 0;
        if(head->next==NULL) return head->val;
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode* newHead=reverse(slow->next);
        ListNode* temp=head;
        int ans=0,max_el=0;
        while(newHead!=NULL)
        {
            ans=temp->val+newHead->val;
            max_el=max(ans,max_el);
            temp=temp->next;
            newHead=newHead->next;
        }
        reverse(newHead);
        return max_el;
    }
};