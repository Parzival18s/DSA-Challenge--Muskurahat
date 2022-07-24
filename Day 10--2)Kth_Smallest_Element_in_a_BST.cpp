class Solution {
public:
    vector<int>v;
    void helper(TreeNode*root)
    {
        if(!root)
            return;
        if(root->left)
            helper(root->left);
        v.push_back(root->val);
        if(root->right)
            helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return v[k-1];
    }
};

//Link--https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/