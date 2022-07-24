class Solution {
public:
    int ans=INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        if(left<0)
            left=0;
        if(right<0)
            right=0;
        ans=max(ans,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int top=helper(root);
        ans=max(ans,top);
        return ans;
    }
};

//Link--https://leetcode.com/problems/binary-tree-maximum-path-sum/