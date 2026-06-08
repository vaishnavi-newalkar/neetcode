class Solution {
public:
    bool isPalindrome(string s) {
        string simplified="";
        for(char i:s){
            i=tolower(i);
            if(isalnum(i)){
                simplified+=i;
            }
        }
        string rev_simplified = simplified;
        reverse(simplified.begin(),simplified.end());
        
        return simplified==rev_simplified;

    }
};
