class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        vector<int> ans;
        while(l<r){
            int difference= target-numbers[l];
            if(numbers[r]==difference){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(difference<numbers[r]) r--;
            else{
                l++;
            }
        }
        return ans;
    }
};
