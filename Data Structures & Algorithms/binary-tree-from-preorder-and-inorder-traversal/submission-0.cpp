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
    
    unordered_map<int,int> index;
    int preOrder=0;

    TreeNode* build(vector<int>& preorder,int left,int right){
        if(left>right) return NULL;

        //pick root from preorder
        int rootVal=preorder[preOrder++];
        TreeNode* root = new TreeNode(rootVal);

        //first index in inorder
        int idx= index[rootVal];
        root->left=build(preorder,left,idx-1);

        root->right = build(preorder,idx+1,right);

        return root;
    }
     
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for(int i=0;i<inorder.size();i++){
                index[inorder[i]]=i;
            }
             
             return build(preorder,0,inorder.size()-1);


    }
};
