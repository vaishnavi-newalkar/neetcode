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
    
    int heightH(TreeNode* root, int & diameter){
        if(!root) return 0;

        int LH=heightH(root->left,diameter);
        int RH= heightH(root->right,diameter);

        diameter=max(diameter,LH+RH);

        return 1+max(heightH(root->left,diameter),heightH(root->right,diameter));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter=0;
        heightH(root,diameter);
        return diameter;
    }
};
