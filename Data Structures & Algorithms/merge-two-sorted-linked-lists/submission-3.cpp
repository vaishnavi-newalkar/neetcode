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
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* newHead= new ListNode(-1); 
        ListNode* tail= newHead;
        while(l1 && l2){
          if (l1->val <= l2->val){
             
             tail->next=l1;
             tail=tail->next;
             l1=l1->next;
          }
          else{
             tail->next=l2;
             tail=tail->next;
             l2=l2->next;
          }
        }

        if(l2) tail->next=l2;
        else tail->next=l1;
        return newHead->next;
    }
};
