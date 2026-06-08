class Solution {
public:
     
    int countNodes(ListNode* head){
        int cnt = 0;
        ListNode* ptr = head;
        while(ptr) {
            cnt++;
            ptr = ptr->next;
        }
        return cnt;
    } 

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        int cnt = countNodes(head);

        // Step 1: Store values
        vector<int> v;
        ListNode* ptr = head;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }

        // Step 2: Reorder using two pointers
        vector<int> ans;
        int i = 0, j = cnt - 1;

        while(i <= j){
            if(i == j){
                ans.push_back(v[i]);
            } else {
                ans.push_back(v[i]);
                ans.push_back(v[j]);
            }
            i++;
            j--;
        }

        // Step 3: Write back into LL
        ptr = head;
        int k = 0;
        while(ptr){
            ptr->val = ans[k++];
            ptr = ptr->next;
        }
    }
};