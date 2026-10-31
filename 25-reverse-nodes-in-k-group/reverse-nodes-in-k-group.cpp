/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;ListNode* 
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* findkthnode(ListNode* temp,int k)
{
    k-=1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;

}
ListNode* reversesublist(ListNode* temp)
{
    if(temp==NULL || temp->next==NULL)
    return temp;
    ListNode* front=temp->next;
    ListNode* newhead=reversesublist(front);
    
    front->next=temp;
    temp->next=NULL;
    return newhead;

}
 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=NULL;
        while(temp!=NULL)
        {
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==NULL)
            {
                if(prevnode)prevnode->next=temp;
            break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
           ListNode* newhead= reversesublist(temp);
            if(temp==head)head=kthnode;
            else{
                prevnode->next=kthnode;
            }
            prevnode=temp;
            temp=nextnode;

        }
        return head;
    }
};