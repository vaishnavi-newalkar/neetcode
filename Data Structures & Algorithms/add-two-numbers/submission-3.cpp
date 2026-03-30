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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        
        int carry =0;
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;

        while( ptr1!=NULL || ptr2!=NULL || carry!=0){
            int val1=(ptr1!=NULL)? ptr1->val:0;
            int val2 = (ptr2!=NULL) ? ptr2->val:0;
            int sum=val1+val2+carry;
            carry = sum/10;
            int digit = sum % 10;
            ListNode* temp = new ListNode(digit);
            curr->next=temp;
            curr=temp;
        if(ptr1) ptr1 = ptr1->next;
        if(ptr2) ptr2 = ptr2->next;
        }
        return dummy->next;

    }
};
