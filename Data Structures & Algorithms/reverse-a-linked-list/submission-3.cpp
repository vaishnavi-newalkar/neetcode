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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        if(head==NULL || head->next==NULL) return head;
        while(head){
           ListNode* t2= head->next;
           head->next=temp;
           temp=head;
           head=t2;
        }
        return temp;
    }
};
