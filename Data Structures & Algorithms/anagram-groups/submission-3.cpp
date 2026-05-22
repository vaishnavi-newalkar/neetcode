class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ana;
        for(auto s: strs){
            string t=s;
            sort(s.begin(),s.end());
            // if(ana.count(s)){
            //     ana[s].push_back(t);
            // }
            ana[s].push_back(t);
        }
        vector<vector<string>> res;
        for(auto s:ana){
          res.push_back(s.second);
        }
        return res;
    }
};
