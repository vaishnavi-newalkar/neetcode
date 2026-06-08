class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int> pref_prod(n, 1);
       vector<int>suff_prod(n, 1);
        int mul=1;
       for(int i=1;i<nums.size();i++){
   
           mul*=nums[i-1];
           pref_prod[i]=mul;
       }
       int mq=1;
       for(int i=n-2;i>=0;i--){
        mq*=nums[i+1];
        suff_prod[i]=mq;
       } 
       vector<int>res(n);
       for(int i=0;i<n;i++){
        res[i]=pref_prod[i]*suff_prod[i];
       }

       return res;
    }
};
