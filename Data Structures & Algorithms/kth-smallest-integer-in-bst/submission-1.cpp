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
    void inorder(TreeNode* root, int& k,int& min_val){
        if(!root) return ;
        inorder(root->left,k,min_val);
        if(root->val>min_val && k>0){
          min_val=root->val;
          k--;
        }
        inorder(root->right,k,min_val);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans=INT_MIN;
        
        inorder(root,k,ans);
        return ans;
    }
};
