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
    void inorder(TreeNode* root, vector<int>& r){
        if(!root) return;
        inorder(root->left,r);
        r.push_back(root->val);
        inorder(root->right,r);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> res;
        inorder(root,res);
        set<int> s(res.begin(),res.end());
        if(s.size()!=res.size()) return false;
        vector<int> copy=res;
        sort(copy.begin(),copy.end());
        return copy==res;
    }
};
