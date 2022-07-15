class Solution {
public:
    int ans=0;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+max(helper(root->left),helper(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int left=helper(root->left);
        int right=helper(root->right);
        ans=max(ans,left+right);
        if(root->left)
            ans=max(ans,diameterOfBinaryTree(root->left));
        if(root->right)
            ans=max(ans,diameterOfBinaryTree(root->right));
        return ans;
    }
};

//Link--https://leetcode.com/problems/diameter-of-binary-tree/submissions/