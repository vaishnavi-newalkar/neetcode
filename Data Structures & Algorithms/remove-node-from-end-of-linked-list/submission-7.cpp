class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head) return nullptr;

        int cnt = 0;
        ListNode* temp = head;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // Remove head
        if (n == cnt) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = head;

        // Move to node just before the one to delete
        for (int i = 1; i < cnt - n; i++) {
            prev = prev->next;
        }

        temp = prev->next;
        prev->next = temp->next;
        delete temp;

        return head;
    }
};