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
    void reverseNode(TreeNode* h){
        if(!h) return ;
        TreeNode* temp = h->left;
        h->left=h->right;
        h->right=temp;
        if(h->left) reverseNode(h->left);
        if (h->right)reverseNode(h->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        reverseNode(root);
        return root;
    }
};
