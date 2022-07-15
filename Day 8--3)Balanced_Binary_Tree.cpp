class Solution {
public:
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+max(helper(root->left),helper(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int left=helper(root->left);
        int right=helper(root->right);
        if(abs(left-right)>1)
            return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};

//Link--https://leetcode.com/problems/balanced-binary-tree/