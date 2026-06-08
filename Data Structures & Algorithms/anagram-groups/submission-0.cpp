class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> answer;
        vector<bool> visited(strs.size(), false);

        for(int i = 0; i < strs.size(); i++) {
            
            if(visited[i]) continue;  // Skip if already grouped
            
            vector<string> helper;
            string t = strs[i];
            sort(t.begin(), t.end());

            helper.push_back(strs[i]);
            visited[i] = true;

            for(int j = i + 1; j < strs.size(); j++) {
                
                if(visited[j]) continue;

                string q = strs[j];
                sort(q.begin(), q.end());

                if(t == q) {
                    helper.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            answer.push_back(helper);
        }

        return answer;
    }
};