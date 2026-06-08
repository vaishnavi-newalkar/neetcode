class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        int n=s1.size();
        sort(s1.begin(),s1.end());
        for(int r=0;r<s2.size();r++){
          while(r-l+1>n){
            l++;
          }
          string temp=s2.substr(l,r-l+1);
          sort(temp.begin(),temp.end());
          if(temp==s1){
            return true;
          }
        }
        return false;
    }
};
