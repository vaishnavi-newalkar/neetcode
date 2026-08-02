class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string,vector<string>> ana;
        for(auto s:strs){
            string t=s;
            sort(t.begin(),t.end());
            ana[t].push_back(s);
        }
        for(auto i:ana){
             v.push_back(i.second);
        }
        return v;
    }
};
