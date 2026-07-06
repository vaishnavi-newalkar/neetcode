class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head;
        ListNode* tail;

        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        tail = head;

        while (list1 && list2) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1)
            tail->next = list1;
        else
            tail->next = list2;

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        ListNode* res = mergeTwoLists(lists[0], lists[1]);

        for (int i = 2; i < lists.size(); i++) {
            res = mergeTwoLists(res, lists[i]);
        }

        return res;
    }
};