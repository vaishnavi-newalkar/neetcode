class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

       if(nums.size()==0) return 0;
       
       set<int> s(nums.begin(),nums.end());
       vector<int> t(s.begin(), s.end());
       int max_len=INT_MIN;
       vector<int> ans;
       if(t.size()==1) return 1;
      int cnt=1;
       for(int i=0;i<t.size()-1;i++){
        if(t[i]+1 == t[i+1]){
          cnt++;
        }
        else{
          max_len=max(max_len,cnt);
          cnt=1;
        }
        max_len=max(max_len,cnt);
       }
       return max_len;
    }
};
