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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp);
            temp=temp->next;
        }
        int l=0,r=v.size()-1;
        vector<ListNode*>reorderedV;
        while(l<r){
            reorderedV.push_back(v[l]);
            reorderedV.push_back(v[r]);
            l++;
            r--;
        }
        if (l == r)
        reorderedV.push_back(v[l]);
        ListNode* newHead = reorderedV[0];
        head = newHead;
        for(int i=1;i<reorderedV.size();i++){
            newHead->next=reorderedV[i];
            newHead=newHead->next;
        }
        newHead->next=nullptr;
        
    }
};
