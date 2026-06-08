class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;     // stores indices
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // Step 1: remove indices outside window
            if(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Step 2: remove smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Step 3: add current index
            dq.push_back(i);

            // Step 4: record answer
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};