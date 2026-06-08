class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     vector<int> output;
     for(int i=0;i<nums.size();i++){
      int temp_product_l=1;
      int temp_product_r=1;
      for(int j=0;j<i;j++){
        temp_product_l*=nums[j];
      }
      if(i==nums.size()-1){
        temp_product_r=1;
      }
      else{
      for(int j=i+1;j<nums.size();j++){
        temp_product_r*=nums[j];
      }
      }
      output.push_back(temp_product_l*temp_product_r);
     }
     return output;
    }
};
