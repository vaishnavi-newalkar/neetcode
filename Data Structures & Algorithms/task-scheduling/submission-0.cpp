class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : tasks)
            freq[ch]++;

        // Max heap {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto &it : freq)
            pq.push({it.second, it.first});

        int cnt = 0;

        while (!pq.empty()) {
            vector<pair<int, char>> temp;
            int workDone = 0;

            // Process one block of size n+1
            for (int i = 0; i <= n; i++) {
                if (pq.empty())
                    break;

                auto curr = pq.top();
                pq.pop();

                curr.first--;

                if (curr.first > 0)
                    temp.push_back(curr);

                workDone++;
            }

            // Push remaining tasks back
            for (auto &p : temp)
                pq.push(p);

            // Count cycles
            if (pq.empty())
                cnt += workDone;
            else
                cnt += (n + 1);
        }

        return cnt;
    }
};