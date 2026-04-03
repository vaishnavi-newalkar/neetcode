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

    bool isSameTree(TreeNode* r,TreeNode* r1){
        if(!r&&!r1) return true;
        if(!r||!r1) return false;

        if(r->val!=r1->val) return false;
        return (isSameTree(r->left,r1->left) && isSameTree(r->right, r1->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root ) return false;
        if (isSameTree(root, subRoot)) return true;
        else return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
