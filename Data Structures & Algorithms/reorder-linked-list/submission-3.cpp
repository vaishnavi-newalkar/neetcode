/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(0), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next) return;

        ListNode* temp = head;
        int cnt = 0;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        int mid = (cnt+1) / 2;
        temp = head;

        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        // Split into two halves
        ListNode* second = temp->next;
        temp->next = nullptr;

        // Reverse second half
        ListNode* prev = nullptr;
        while (second) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }

        // Merge alternately
        ListNode* first = head;
        second = prev;

        while (second) {
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};