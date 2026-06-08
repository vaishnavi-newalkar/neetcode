class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string,vector<string>> checklist;

        for(int i=0;i<strs.size();i++){
          string q=strs[i];
          sort(q.begin(),q.end());
          checklist[q].push_back(strs[i]);
        }
        for(auto i : checklist){
          answer.push_back(i.second);
        }
        return answer;
    }
};
