class Solution {
public:
    unordered_map<int, int> idx;

    TreeNode* solve(vector<int>& preorder, int preStart,
                    int inStart, int inEnd) {

        // Base case
        if (inStart > inEnd)
            return nullptr;

        // Root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Root index in inorder
        int rootIndex = idx[root->val];

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = solve(preorder,
                           preStart + 1,
                           inStart,
                           rootIndex - 1);

        // Build right subtree
        root->right = solve(preorder,
                            preStart + leftSize + 1,
                            rootIndex + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            idx[inorder[i]] = i;

        return solve(preorder, 0, 0, inorder.size() - 1);
    }
};