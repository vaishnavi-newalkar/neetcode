/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int height(TreeNode* root,int & ans){
        if(!root) return 0;
        int LH = height(root->left,ans);
        int RH = height(root->right,ans);
        if(abs(LH-RH)>1) {
            ans=-1;}
        if(ans==-1) return -1;    
        return 1+max(LH,RH);
    }
    bool isBalanced(TreeNode* root) {
        int ans=0;
        height(root,ans);
        return ans==-1 ? false : true;
    }
};
