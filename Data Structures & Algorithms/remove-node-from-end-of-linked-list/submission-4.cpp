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
        int cnt = 0;
        ListNode* ptr=head;
        while(ptr){
            cnt++;
            ptr=ptr->next;
        }

        int loop=cnt-n;
        ListNode* temp=head;
        // if (cnt==1 && n==1){
        //     return nullptr;
        // }
        if(cnt-n==0){
            return head->next;
        }
        for(int i=0;i<loop-1;i++){
          temp=temp->next;
        }
        ListNode* helper=temp->next;
          temp->next=helper->next;
          delete helper;

     return head;
    }
};
